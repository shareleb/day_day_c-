#pragma once
#include <vector>
#include <stack>

namespace leb {

	template <class T>
	class TreeNode   //�ڵ�ģ��
	{
		int m_bf;   //ƽ������
		T m_data;   //����
		TreeNode<T> * m_left; //����
 		TreeNode<T> * m_right; //�Һ���
		TreeNode<T> * m_parent;  //����
	public:
		TreeNode(const T & val = T()) :     //���캯��
			m_bf(0),
			m_data(val),
			m_left(nullptr),
			m_right(nullptr),
			m_parent(nullptr)
		{}

		template <class T>
		friend class AVLTree;      //AVL
	};

	template <class T>
	class AVLTree
	{
		TreeNode<T> * m_root;    //���ڵ�

		void destroy(TreeNode<T> * root) //����AVLtree 
		{
			//�õĶ������ĺ����������
			if (root)      
			{
				destroy(root->m_left);
				destroy(root->m_right);
				delete root;
			}
		}
		//����

		/*
		      O    <-parent
 	    	 O	O   <---pre;
     		  0  O  <---cur;
���������	 -> 0  O
		
		*/

		void lRound(TreeNode<T> * pre)    //
		{
			TreeNode<T> * parent = pre->m_parent;       
			TreeNode<T> * cur = pre->m_right;       

			cur->m_parent = parent;   //�Ȱ�cur�ĸ��׸���
			if (parent)  //������ײ��Ǹ��ڵ㡣 ���parentָ���ӡ�
			{
				if (parent->m_left == pre)   //���pre��parent�����ӣ�  ���cur��Ϊparent������
				{
					parent->m_left = cur;
				}
				else
				{
					parent->m_right = cur;     //���pre��parent���Һ��ӣ�  ���cur��Ϊparent���Һ���  
				}
			}
			else
			{ 
				m_root = cur;  //�ø���root�ڵ㡣
			}

			pre->m_right = cur->m_left;      //��cur�����ӵ���pre���Һ���
			if (cur->m_left)     //
			{
				cur->m_left->m_parent = pre;
			}

			cur->m_left = pre;      //��pre�ҵ�cur��������
			pre->m_parent = cur;    //��pre�ҵ�cur��������

			cur->m_bf = pre->m_bf = 0;   //��ƽ��������Ϊ0��
		}
		//����
		/*
         parent--->        O
	     pre	--->	 O   O
         cur-->        O   0
			         0 	0  <---����û��	
		
		
		*/
		void rRound(TreeNode<T> * pre)    
		{
			TreeNode<T> * parent = pre->m_parent; 
			TreeNode<T> * cur = pre->m_left;

			cur->m_parent = parent;    //�ȸ�cur�ĸ��׸���
			if (parent)  //������ײ��Ǹ��ڵ㡣 ���parentָ���ӡ�
			{
				if (parent->m_left == pre)    //���pre��parent�����ӣ�  ���cur��Ϊparent������
				{
					parent->m_left = cur;
				}
				else
				{
					parent->m_right = cur;  //���pre��parent���Һ��ӣ�  ���cur��Ϊparent���Һ���
				}
			}
			else
			{
				m_root = cur;  //�ø���root�ڵ㡣
			}

			pre->m_left = cur->m_right;   //��cur�����ӵ���pre���Һ���
			if (cur->m_right)
			{
				cur->m_right->m_parent = pre;
			}

			cur->m_right = pre;
			pre->m_parent = cur;

			cur->m_bf = pre->m_bf = 0;
		}

		//������


		void rlRound(TreeNode<T> * pre)
		{
			TreeNode<T> * right = pre->m_right;
			TreeNode<T> * newroot = right->m_left;

			int flag = newroot->m_bf;

			rRound(pre->m_right);   //������ ������
			lRound(pre);    

			if (flag == -1)     //��סnewroot��ƽ�����ӣ� ��Ϊ-1 ʱ   right Ϊ1   
			{
				right->m_bf = 1;
			}
			else if (flag == 1)    //����Ϊ1ʱ��  preΪ-1
			{
				pre->m_bf = -1;
			}
		}
		//������
		void lrRound(TreeNode<T> * pre)
		{
			TreeNode<T> * left = pre->m_left;
			TreeNode<T> * newroot = left->m_right;

			int flag = newroot->m_bf;

			lRound(pre->m_left);
			rRound(pre);

			if (flag == -1)    //��סnewroot��ƽ�����ӣ� ��Ϊ-1 ʱ   preΪ1
			{
				pre->m_bf = 1;
			} 
			else if (flag == 1)   //����Ϊ1ʱ��  preΪ-1
			{
				left->m_bf = -1;
			}
		}
	public:
		AVLTree():
			m_root(nullptr)
		{}

		~AVLTree()
		{
			destroy(m_root);
		}

		//����
		bool insert(const T &val)
		{
			if (m_root == nullptr)
			{
				m_root = new TreeNode<T>(val);
				return true;
			}

			TreeNode<T> * cur = m_root;
			TreeNode<T> * pre = nullptr;

			while (cur)
			{
				if (val < cur->m_data)
				{
					pre = cur;
					cur = cur->m_left;
				}
				else if (val > cur->m_data)
				{
					pre = cur;
					cur = cur->m_right;
				}
				else
				{
					return false;
				}
			}

			cur = new TreeNode<T>(val);
			if (val < pre->m_data)
			{
				pre->m_left = cur;
			}
			else
			{
				pre->m_right = cur;
			}

			cur->m_parent = pre;

			while (pre)
			{
				if (pre->m_left == cur)
				{
					pre->m_bf--;
				}
				else
				{
					pre->m_bf++;
				}

				if (pre->m_bf == 0)    //��������������ƽ�����ӵ�ȷ��
				{
					break;
				}
				else if (pre->m_bf == 1 || pre->m_bf == -1)     
				{
					cur = pre;
					pre = pre->m_parent;
				}
				else
				{
					if (pre->m_bf == 2)
					{
						if (cur->m_bf == 1)
						{
							lRound(pre);
						}
						else
						{
							rlRound(pre);
						}
					}
					else
					{
						if (cur->m_bf == 1)
						{
							lrRound(pre);
						}
						else
						{
							rRound(pre);
						}
					}
					break;
				}
			}
			return true;
		}
		//ɾ��
		bool erase(const T &val)
		{
			if (m_root == nullptr)
			{
				return false;
			}

			TreeNode<T> * cur = m_root;
			TreeNode<T> * pre = m_root;

			while (cur)
			{
				if (val < cur->m_data)
				{
					pre = cur;
					cur = cur->m_left;
				}
				else if (val > cur->m_data)
				{
					pre = cur;
					cur = cur->m_right;
				}
				else
				{
					break;
				}
			}

			if (cur == nullptr)
			{
				return false;
			}

			if (cur->m_left && cur->m_right)
			{
				TreeNode<T> * cur2 = cur->m_left;
				TreeNode<T> * pre2 = cur;

				if (cur2->m_right)
				{
					for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
					pre2->m_right = cur2->m_left;
					cur2->m_left = cur->m_left;
				}

				cur2->m_right = cur->m_right;

				if (cur == pre)
				{
					m_root = cur2;
				}
				else
				{
					if (cur->m_data < pre->m_data)
					{
						pre->m_left = cur2;
					}
					else
					{
						pre->m_right = cur2;
					}
				}

				delete cur;
			}
			else if (cur->m_left)
			{
				if (cur == pre)
				{
					m_root = cur->m_left;
				}
				else
				{
					if (cur->m_data < pre->m_data)
					{
						pre->m_left = cur->m_left;
					}
					else
					{
						pre->m_right = cur->m_left;
					}
				}
				delete cur;
			}
			else
			{
				if (cur == pre)
				{
					m_root = cur->m_right;
				}
				else
				{
					if (cur->m_data < pre->m_data)
					{
						pre->m_left = cur->m_right;
					}
					else
					{
						pre->m_right = cur->m_right;
					}
				}

				delete cur;
			}
		}

		/*
		���ǲ���������������
			�������������У�
				a��������û���Һ���
					ֱ�������Ӽ̳��Լ����Һ��Ӻ͸���
				b�����������Һ���
					һ·���ң��ҵ�����һ���Һ��ӣ�Ȼ��������ӵ�
					���������������׵��������ϣ�Ȼ�������̳�Ҫɾ����
					����˼ʹ�ϵ�����������͸��ף�
				��Ҫɾ���Ľڵ��Ǹ��ڵ�ʱ�����ü̳и��׹�ϵ����Ҫ�޸�
				���ڵ�ָ��
			��ֻ��������
				ֱ�����������̳��Լ��ĸ��׹�ϵ�����Ҫɾ���Ǹ�����ô
				ֱ�ӻ������ɡ�
			������
				ֱ���������������߿գ��̳��Լ��ĸ��׹�ϵ������ͬ��
		*/

		//���򲻱䡣
		std::vector<T> InOrder()
		{
			std::stack<TreeNode<T> *> s;
			std::vector<T> res;
			TreeNode<T> * cur = m_root;

			while (cur || !s.empty())
			{
				for (; cur; cur = cur->m_left)
				{
					s.push(cur);
				}

				if (!s.empty())
				{
					cur = s.top();
					res.push_back(cur->m_data);
					s.pop();

					cur = cur->m_right;
				}
			}

			return res;
		}
	};



};