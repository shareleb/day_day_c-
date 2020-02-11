#pragma once

#include <vector>
#include <stack>

namespace leb {

	template <class T>
	class TreeNode
	{
		T m_data;
		TreeNode<T> * m_left;
		TreeNode<T> * m_right;
	public:
		TreeNode(const T & val = T()) :
			m_data(val),
			m_left(nullptr),
			m_right(nullptr)
		{}

		template <class T>
		friend class BinarySortTree;
	};

	template <class T>
	class BinarySortTree
	{
		TreeNode<T> * m_root;

		void destroy(TreeNode<T> * root)
		{
			if (root)
			{
				destroy(root->m_left);
				destroy(root->m_right);
				delete root;
			}
		}
	public:
		BinarySortTree() :
			m_root(nullptr)
		{}

		~BinarySortTree()
		{
			destroy(m_root);
		}

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

			return true;
		}

		bool erase(const T &val)     //������������ɾ��
		{ 
			if (m_root == nullptr)      //�����Ϊ�գ���ֱ��ɾ��ʧ��
			{
				return false;
			}

			TreeNode<T> * cur = m_root;    //��¼��ǰ�ڵ�     ��Ϊ����Ҫ����ɾ���ڵ�ĸ��� �ڵ�ͺ��ӽڵ㡣
			TreeNode<T> * pre = m_root;    //��¼ǰ���ڵ�

			while (cur)    //Ѱ��Ҫɾ���ڵ�λ��
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
			//���������ֽ��  ��1��curΪ�գ���ʱ֤���ò����ڣ�  2.�ҵ��ˣ� pre��cur�ĸ��ף����ǲ�֪��pre�Ƿ��к���

			//1���յ�ʱ��֤�������ڣ���false
			if (cur == nullptr)
			{
				return false;
			}
			

			if (cur->m_left && cur->m_right)     
			{
#if 0
			/*	TreeNode<T> * cur2 = cur->m_left;
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

				delete cur;*/
#else
				TreeNode<T> * cur2 = cur->m_left;
				TreeNode<T> * pre2 = cur;

				if (cur2->m_right)
				{
					for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
					pre2->m_right = cur2->m_left;
				}
				cur->m_data = cur2->m_data;

				delete cur2;
#endif

			}
			else if (cur->m_left)  //cur �����ӣ�û���Һ��ӵ�ʱ��    
			{
				if (cur == pre)    //cur�Ǹ��ڵ�ʱ��ֱ�Ӹ��¸��ڵ�
				{
					m_root = cur->m_left;
				}
				else   				{
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
			else  //���Һ��Ӷ�û��
			{
				if (cur == pre)    //����ҵ��ľ��Ǹ��ڵ㣬��ô��Ҫ����m_root�ڵ㡣
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
