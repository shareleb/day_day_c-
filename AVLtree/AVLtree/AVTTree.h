#pragma once
#include <vector>
#include <stack>

namespace leb {

	template <class T>
	class TreeNode   //节点模板
	{
		int m_bf;   //平衡因子
		T m_data;   //数据
		TreeNode<T> * m_left; //左孩子
 		TreeNode<T> * m_right; //右孩子
		TreeNode<T> * m_parent;  //父亲
	public:
		TreeNode(const T & val = T()) :     //构造函数
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
		TreeNode<T> * m_root;    //根节点

		void destroy(TreeNode<T> * root) //销毁AVLtree 
		{
			//用的二叉树的后序进行销毁
			if (root)      
			{
				destroy(root->m_left);
				destroy(root->m_right);
				delete root;
			}
		}
		//左旋

		/*
		      O    <-parent
 	    	 O	O   <---pre;
     		  0  O  <---cur;
这个可能有	 -> 0  O
		
		*/

		void lRound(TreeNode<T> * pre)    //
		{
			TreeNode<T> * parent = pre->m_parent;       
			TreeNode<T> * cur = pre->m_right;       

			cur->m_parent = parent;   //先把cur的父亲改了
			if (parent)  //如果父亲不是根节点。 则把parent指向孩子。
			{
				if (parent->m_left == pre)   //如果pre是parent的左孩子，  则把cur作为parent的左孩子
				{
					parent->m_left = cur;
				}
				else
				{
					parent->m_right = cur;     //如果pre是parent的右孩子，  则把cur作为parent的右孩子  
				}
			}
			else
			{ 
				m_root = cur;  //该更新root节点。
			}

			pre->m_right = cur->m_left;      //把cur的左孩子当做pre的右孩子
			if (cur->m_left)     //
			{
				cur->m_left->m_parent = pre;
			}

			cur->m_left = pre;      //把pre挂到cur的左上面
			pre->m_parent = cur;    //把pre挂到cur的右上面

			cur->m_bf = pre->m_bf = 0;   //把平衡因子设为0；
		}
		//右旋
		/*
         parent--->        O
	     pre	--->	 O   O
         cur-->        O   0
			         0 	0  <---可能没有	
		
		
		*/
		void rRound(TreeNode<T> * pre)    
		{
			TreeNode<T> * parent = pre->m_parent; 
			TreeNode<T> * cur = pre->m_left;

			cur->m_parent = parent;    //先改cur的父亲该了
			if (parent)  //如果父亲不是根节点。 则把parent指向孩子。
			{
				if (parent->m_left == pre)    //如果pre是parent的左孩子，  则把cur作为parent的左孩子
				{
					parent->m_left = cur;
				}
				else
				{
					parent->m_right = cur;  //如果pre是parent的右孩子，  则把cur作为parent的右孩子
				}
			}
			else
			{
				m_root = cur;  //该更新root节点。
			}

			pre->m_left = cur->m_right;   //把cur的左孩子当做pre的右孩子
			if (cur->m_right)
			{
				cur->m_right->m_parent = pre;
			}

			cur->m_right = pre;
			pre->m_parent = cur;

			cur->m_bf = pre->m_bf = 0;
		}

		//右左旋


		void rlRound(TreeNode<T> * pre)
		{
			TreeNode<T> * right = pre->m_right;
			TreeNode<T> * newroot = right->m_left;

			int flag = newroot->m_bf;

			rRound(pre->m_right);   //先右旋 再左旋
			lRound(pre);    

			if (flag == -1)     //记住newroot的平衡因子， 若为-1 时   right 为1   
			{
				right->m_bf = 1;
			}
			else if (flag == 1)    //否者为1时，  pre为-1
			{
				pre->m_bf = -1;
			}
		}
		//左右旋
		void lrRound(TreeNode<T> * pre)
		{
			TreeNode<T> * left = pre->m_left;
			TreeNode<T> * newroot = left->m_right;

			int flag = newroot->m_bf;

			lRound(pre->m_left);
			rRound(pre);

			if (flag == -1)    //记住newroot的平衡因子， 若为-1 时   pre为1
			{
				pre->m_bf = 1;
			} 
			else if (flag == 1)   //否者为1时，  pre为-1
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

		//插入
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

				if (pre->m_bf == 0)    //从下往上来进行平衡因子的确定
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
		//删除
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
		看是不是有左右子树：
			①左右子树都有：
				a、左子树没有右孩子
					直接让左孩子继承自己的右孩子和父亲
				b、左子树有右孩子
					一路向右，找到最后的一个右孩子，然后将这个孩子的
					左子树挂在它父亲的右子树上，然后让它继承要删除节
					点的人际关系（左右子树和父亲）
				当要删除的节点是根节点时，不用继承父亲关系，但要修改
				根节点指向。
			②只有左子树
				直接让左子树继承自己的父亲关系，如果要删的是根，那么
				直接换根即可。
			③其他
				直接让右子树（或者空）继承自己的父亲关系，其他同上
		*/

		//中序不变。
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