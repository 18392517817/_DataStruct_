#pragma once

#include<iostream>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K,V> *_left;
	AVLTreeNode<K,V> *_right;
	AVLTreeNode<K,V> *_parent;

	K _key;
	V _val;
	int _bf;

	AVLTreeNode(const K &key,const V&val)
		:_left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _key(key)
		, _val(val)
		, _bf(0)
	{}

};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(NULL)
	{}
	bool Insert(const K &key, const V &val)
	{
		//1.����
		if (_root == NULL)
		{
			_root = new Node(key, val);
			return true;
		}
		//2.���Ҳ���λ��
		Node* parent = NULL;
		Node*cur = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, val);

		if (parent->_key > key)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		

		//bool isRotate = false;
		//3.������
		while (parent)
		{
			if (parent->_left == cur)
				parent->_bf--;
			else if (parent->_right==cur)
				parent->_bf++;
			else
			{
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			else//-2,2
			{
				//isRotate = true;
				if (parent->_bf == 2)
				{
					//����ת
					if (cur->_bf == 1)
					{
						_RotateL(parent);
					}
					else//-1
					{
						if (key<cur->_key)
							_RotateRL(parent,true);
						else
							_RotateRL(parent, false);

					}
				 }
				 else//-2
				 {
					//�ҵ���ת
					if (cur->_bf == -1)
					{
						_RotateR(parent);
					}
					else//-1
					{
						if (key>cur->_key)
							_RotateLR(parent,true);
						else
							_RotateLR(parent, false);

					}
				 }
				 break;
			}	

		}
	/*
		if (isRotate)
		{
			Node *ppNode = parent->_parent->_parent;

			if (ppNode == NULL)
			{	
				_root = parent;
			
			}
			else
			{
				if (ppNode->_key < parent->_key)
				{
					ppNode->_right = parent;
				}
				else
				{
					ppNode->_left = parent;
				}
			}
		}*/
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	int Height()
	{
		return _Height(_root);
	}

	bool IsBlance()
	{
		return _IsBlance(_root);	
	}
protected:
	bool _IsBlance(Node*root)
	{
		if (root==NULL)
		{
			return true;
		}
		int left = _Height(root->_left);
		int right = _Height(root->_right);
		
		int bf = abs(right-left);
		if (bf>1)
		{
			return false;
		}
		//
		if (bf!=abs(root->_bf))
		{
			cout << root->_key << "��ƽ�����Ӳ���" << endl;
			return false;
		}

		return _IsBlance(root->_left) && _IsBlance(root->_right);
	}
	int _Height(Node* root)
	{
		if (root == NULL)
			return 0;

		int left = _Height(root->_left) + 1;
		int right = _Height(root->_right) + 1;
		
		return left > right ? left : right;
	}
	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_key<<" ";
		_InOrder(root->_right);
	}

	//����ת
	void _RotateL(Node*&parent)
	{
		Node*subR = parent->_right;
		Node*subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;
		 if (parent->_parent == NULL)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			subR->_parent = parent->_parent;
			if (subR->_key > subR->_parent->_key)
				subR->_parent->_right = subR;
			else
				subR->_parent->_left = subR;

		} 

		parent->_parent = subR;
		
		//ƽ������
		parent->_bf = subR->_bf = 0;

		parent = subR;

	}
	/*   30
	    /
	  20
	 /
	10      */
	void _RotateR(Node*&parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;
	 	if (parent->_parent == NULL)
		{
			_root = subL;
			subL->_parent = NULL;
		}
		else
		{
			subL->_parent = parent->_parent;
			if (subL->_key > subL->_parent->_key)
				subL->_parent->_right = subL;
			else
				subL->_parent->_left = subL;
		} 
		 

		parent->_parent = subL;
	

		//ƽ������
		parent->_bf = subL->_bf = 0;

		parent = subL;
	}
	/*   30
		/
	  10
	    \
	     20    */
	void _RotateLR(Node*&parent,bool isright )
	{
		_RotateL(parent->_left);
		_RotateR(parent);

		if (isright)
		{
			parent->_left->_bf--;
		}
		else
		{
		}
	}
	void _RotateRL(Node*&parent,bool isleft)
	{
		_RotateR(parent->_right);
		_RotateL(parent);
		if (isleft)
		{
			parent->_right->_bf++;
		}
		else
		{
			//do nothing
		}

	/*	Node * subR = parent->_right;
		Node * subRL = subR->_left;*/

	}

private:
	Node* _root;

};


void Test1()
{
	AVLTree<int, int> t1;
	//int a[] = {16,3,7,11,9,26,18,14,15};
	 //int a[] = {1,2,3};

	/*			90
			   /  \
	     	  30   100
				   /  
				  95
				    \
					(98)
			
	*/
	//int a[] = { 90, 30, 100, 95, 98 };//������ת

	//int a[] = { 90, 30, 100, 60, 50 };//������ת

	int a[] = {16,3,7,11,9,26,18,14,15};
	for (size_t i = 0; i < sizeof(a) / sizeof(int);++i)
	{
		t1.Insert(a[i],i);
	}
	t1.InOrder();
	cout << "IsBlance?"<<t1.IsBlance() << endl;;
}
