#pragma once

#include <queue>
#include <stack>

template<class T>
struct TreeNode
{
	T _value;
	TreeNode<T>* _firstChild;
	TreeNode<T>* _nextBrother;
};

template<class T>
struct BinaryTreeNode
{
	T _value;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;

	BinaryTreeNode(const T& value)
		:_value(value)
		,_left(NULL)
		,_right(NULL)
	{}
};

template<class T>
class Binarytree
{
public:	
	Binarytree()
		:_root(NULL)
	{}

	Binarytree(char* str)
	{
		_CreateTree(_root, str);
	}

	Binarytree(T* a, size_t size, const T& invalid)
	{
		//_CreateTree(_root, str);
	}

	Binarytree(const Binarytree<T>& t)
	{
		_root = _CopyTree(t._root);
	}

	/*Binarytree& operator=(Binarytree<T>& t)
	{
		if (this != &t)
		{
			this->~Binarytree();

			_root = _CopyTree(t._root);
		}

		return *this;
	}*/

	Binarytree<T>& operator=(Binarytree<T> t)
	{
		swap(_root, t._root);
		return *this;
	}

	~Binarytree()
	{
		 _DestoryTree(_root);
	}

	void _CreateTree(BinaryTreeNode<T>*& root, char*& str)
	{
		if (*str != '\0' && *str != '#')
		{
			root = new BinaryTreeNode<T>(*str);

			_CreateTree(root->_left, ++str);
			if (*str == '\0')
			{
				return;
			}
			_CreateTree(root->_right, ++str);
		}
	}

	void PrevOrder()
	{
		_PrevOrder(_root);
		cout<<endl;
	}

	void PrevOrder_NonR()
	{
		stack<BinaryTreeNode<T>* > s;
		if (_root)
		{
			s.push(_root);
		}

		while (!s.empty())
		{
			BinaryTreeNode<T>* top = s.top();
			cout<<top->_value<<" ";
			s.pop();

			if (top->_right)
				s.push(top->_right);

			if (top->_left)
				s.push(top->_left);
		}

		cout<<endl;
	}

	void InOrder_NonR()
	{
		stack<BinaryTreeNode<T>* > s;
		BinaryTreeNode<T>* cur = _root;

		while(cur || !s.empty())
		{
			// 左节点都进行入栈
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			if (!s.empty())
			{
				BinaryTreeNode<T>* top = s.top();
				cout<<top->_value<<" ";
				s.pop();

				if (top->_right)
				{
					cur = top->_right;
				}
			}
		}

		cout<<endl;
	}

	void PostOrder_NonR()
	{
		stack<BinaryTreeNode<T>* > s;
		BinaryTreeNode<T>* cur = _root;
		BinaryTreeNode<T>* visitedNode = NULL;

		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}

			// 右为空或者右节等于上一个访问的节点时，表示左右子树均已访问
			BinaryTreeNode<T>* top = s.top();
			if (top->_right == NULL || top->_right == visitedNode)
			{
				s.pop();
				cout<<top->_value<<" ";
				visitedNode = top;
			}
			else
			{
				cur = top->_right;
			}
		}
	}

	void InOrder();
	void PostOrder()
	{
		_PostOrder(_root);
		cout<<endl;
	}
	void LevelOrder()
	{
		_LevelOrder(_root);
		cout<<endl;
	}

	int Size()
	{
		return _Size(_root);
	}

	int Depth()
	{
		return _Depth(_root);
	}

protected:

	void _DestoryTree(BinaryTreeNode<T>*& root)
	{
		if (root)
		{
			_DestoryTree(root->_left);
			_DestoryTree(root->_right);

			delete root;
			root = NULL;
		}
	}

	BinaryTreeNode<T>* _CopyTree(BinaryTreeNode<T>* root)
	{
		BinaryTreeNode<T>* copyRoot = NULL;
		if (root)
		{
			copyRoot = new BinaryTreeNode<T>(root->_value);
			copyRoot->_left = _CopyTree(root->_left);
			copyRoot->_right = _CopyTree(root->_right);
		}

		return copyRoot;
	}

	int _Size(BinaryTreeNode<T>* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		
		if (root->_left == NULL && root->_right == NULL)
		{
			return 1;
		}

		return 1 + _Size(root->_left) + _Size(root->_right);
	}

	int _Depth(BinaryTreeNode<T>* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		int leftDepth = _Depth(root->_left);
		int rightDepth = _Depth(root->_right);

		return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
	}

	void _PrevOrder(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			cout<<root->_value<<" ";

			if (root->_left)
				_PrevOrder(root->_left);

			if (root->_right)
				_PrevOrder(root->_right);
		}
	}

	void _PostOrder(BinaryTreeNode<T>* root)
	{
		if (root)
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);

			cout<<root->_value<<" ";
		}
	}

	void _LevelOrder(BinaryTreeNode<T>* root)
	{
		queue<BinaryTreeNode<T>*> q;
		if (root)
		{
			q.push(root);
		}

		while (!q.empty())
		{
			BinaryTreeNode<T>* front = q.front();
			cout<<front->_value<<" ";
			q.pop();
			
			if(front->_left)
				q.push(front->_left);

			if (front->_right)
				q.push(front->_right);
		}
	}

private:
	BinaryTreeNode<T>* _root;
};

void Test1()
{
	char* str = "123##4##56###";
	Binarytree<char> bt1(str);

	/*int a[10] = {0, 1, 2, -1, -1, 4, -1, -1, 5, 6};
	Binarytree<int> bt1(a, 10, -1);*/

	//bt1.PrevOrder();
	bt1.PrevOrder_NonR();
	//bt1.InOrder_NonR();
	//bt1.PostOrder_NonR();
	//bt1.LevelOrder();
	//bt1.PostOrder();

	//cout<<"Size:"<<bt1.Size()<<endl;
	//cout<<"Depth:"<<bt1.Depth()<<endl;

	//Binarytree<char> bt2(bt1);
	//bt2.PrevOrder_NonR();

	Binarytree<char> bt3;
	bt3 = bt1;
	bt3.PrevOrder_NonR();
}

template<class T>
struct BinaryTreeNode_P
{
	BinaryTreeNode_P<T>* _left;
	BinaryTreeNode_P<T>* _right;
	BinaryTreeNode_P<T>* _parent;

	T _data;

	BinaryTreeNode_P(const T& x)
		:_left(NULL)
		,_right(NULL)
		,_parent(NULL)
		,_data(x)
	{}
};

template<class T>
class BinaryTree_P
{
public:
	BinaryTree_P(const T* array, size_t size)
		:_root(NULL)
	{
		int index = 0;
		_CreateTree(_root, array, index, size);
	}

protected:
	static void _CreateTree(BinaryTreeNode_P<T>*& root, const T* array, int& index, size_t size)
	{
		if (index < size && array[index] != '#')
		{
			root = new BinaryTreeNode_P<T>(array[index]);

			_CreateTree(root->_left, array, ++index, size);

			if (root->_left)
			{
				root->_left->_parent = root;
			}

			_CreateTree(root->_right, array, ++index, size);

			if (root->_right)
			{
				root->_right->_parent = root;
			}
		}
	}

private:
	BinaryTreeNode_P<T>* _root;
};


void TestBinaryTree_P()
{
	int array[20] = {1, 2, 3, '#','#',4,'#','#', 5, 6};
	BinaryTree_P<int> tree(array, 10);
}