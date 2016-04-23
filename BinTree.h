#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>

template<class Type>
class BinTree;

template<class Type>
class TreeNode
{

friend  class BinTree<Type>;
public:
	TreeNode():data(Type())
	{}
	TreeNode(Type d,TreeNode<Type> *lift=NULL,TreeNode<Type> *right=NULL)
		:data(d),lchild(lift),rchild(right)
	{}
	~TreeNode()
	{}
private:
	Type  data;
	TreeNode<Type> * lchild;
	TreeNode<Type> * rchild;
};



template<class Type>
class BinTree
{
public:
	BinTree():root(NULL)
	{}
	BinTree(Type ref):root(NULL),refvalue(ref)
	{}
	~BinTree()
	{}
public:
	void Creattree()
	{
		Creattree(root);
	}
	void CreateTree(const char *str)
	{	 
		CreateTree(root, str);
	}
protected:
	void CreateTree( TreeNode<Type> *&t,const char *&str)
	{ 
		assert(str);
		if(*str == refvalue || *str == '\0')
		{
			t = NULL;  
		}
		else
		{
			t = new  TreeNode<Type>(*str);
			CreateTree(t->lchild,++str );
			CreateTree(t->rchild,++str);	 
		} 
		
		
	}
	//ABC##DE##F##G#H##
	void Creattree( TreeNode<Type> *&t)
	{
		Type Item;
		cin>>Item;
		if(Item == refvalue)
			t = NULL;
		else
		{
			t = new  TreeNode<Type>(Item);
			Creattree(t->lchild);
			Creattree(t->rchild);
		}
	}
	 
public:
	void PreOrder( )
	{  
		PreOrder(root);
	}
	void InOrder( )
	{
		InOrder(root);
	}
	void PostOrder( )
	{
		PostOrder (root); 
	}
	TreeNode<Type> * Parent(Type key)
	{
		TreeNode<Type> *q;
		q=Parent(root,key);
		return q;
		
	}
	void CreatTree_pre(char *VLR,char *LVR,int n)
	{
		CreatTree_pre( root, VLR, LVR,  n);
	}
     void CreatTree_post(char *RLV,char *LVR ,int n)
	 {
		CreatTree_post(root,RLV,LVR,n);
	 }
protected:
    void CreatTree_post(TreeNode<Type> *&t,char *LRV,char *LVR,int n)
	{int k=0;
		if(n==0)
			return ;
		
		else
		{
		
		    while(LRV[n]!=LVR[k])
				k++;
		}
          t= new TreeNode<Type>(LRV[k])  ;
		CreatTree_post( t->rchild, LRV+k+1, LVR ,  n-1);

	CreatTree_post( t->lchild, LRV+1, LVR,  k);  
	}
	void CreatTree_pre(TreeNode<Type> *&t,char *VLR,char *LVR,int n)
	{
		if(n==0)
			return;
		else
		{	
			int k = 0;
			while(VLR[0]!=LVR[k])
			{
				k++;
			}
		     t= new TreeNode<Type>(VLR[0])  ;
			CreatTree_pre( t->lchild, VLR+1, LVR,  k);//我把LVR写成LVR+k-n,结果？死了
			CreatTree_pre( t->rchild, VLR+k+1, LVR+k+1,  n-k-1);

		}
	}
	  
	TreeNode<Type> * Parent(TreeNode<Type> *p,Type &key)
	{
		if(p==NULL||p->data==key)
			return NULL;
		static TreeNode<Type>*q ;
		
		if((p->lchild!=NULL&&p->lchild->data==key) || 
			(p->rchild!=NULL&&p->rchild->data==key))
		{
			q=p;
			return q;	 
		}
		{
			if(p->lchild!=NULL)
				Parent(p->lchild,key);
			if(p->rchild!=NULL)
				Parent(p->rchild,key);
		}
		return q;
	}
	
	
	void PreOrder(TreeNode<Type> *root)     //非递归前序遍历 
	{
		
		stack<TreeNode<Type> *> s;
		TreeNode<Type> *p=root;
		while(p!=NULL||!s.empty())
		{
			while(p!=NULL)
			{
				cout<<p->data<<" ";
				s.push(p);
				p=p->lchild;
			}
			if(!s.empty())
			{
				p=s.top();
				s.pop();
				p=p->rchild;
			}
		}
	}
	void InOrder(TreeNode<Type> *root)      //非递归中序遍历
	{
		stack<TreeNode<Type>*> s;
		TreeNode<Type> *p=root;
		while(p!=NULL||!s.empty())
		{
			while(p!=NULL)
			{
				s.push(p);
				p=p->lchild;
			}
			if(!s.empty())
			{
				p=s.top();
				cout<<p->data<<" ";
				s.pop();
				p=p->rchild;
			}
		}    
	} 
	void PostOrder2(TreeNode<Type> *root)    //非递归后序遍历
	{
		stack<TreeNode<Type>*> s;
		TreeNode<Type> *p=root;
		TreeNode<Type> *temp;
		while(p!=NULL||!s.empty())
		{
			while(p!=NULL)              //沿左子树一直往下搜索，直至出现没有左子树的结点 
			{
				s.push(p);
				p=p->lchild;
			}
			if(!s.empty())
			{
				temp=s.top();
				s.pop();
				if(temp->isFirst==true)     //表示是第一次出现在栈顶 
				{
					temp->isFirst=false;
					s.push(temp);
					p=temp->btnode->rchild;    
				}
				else                        //第二次出现在栈顶 
				{
					cout<<temp->btnode->data<<" ";
					p=NULL;
				}
			}
		}    
	} 
	
	void PostOrder (TreeNode<Type>*root)     //非递归后序遍历
	{
		stack<TreeNode<Type>*> s;
		TreeNode<Type> *cur;                      //当前结点 
		TreeNode<Type> *pre=NULL;                 //前一次访问的结点 
		s.push(root);
		while(!s.empty())
		{
			cur=s.top();
			if((cur->lchild==NULL&&cur->rchild==NULL)||
				(pre!=NULL && (pre==cur->lchild || pre==cur->rchild)))
			{
				cout<<cur->data<<" ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
				s.pop();
				pre=cur; 
			}
			else
			{
				if(cur->rchild!=NULL)
					s.push(cur->rchild);
				if(cur->lchild!=NULL)    
					s.push(cur->lchild);
			}
		}    
	}
	/////////////////////////////////////////////
	void PostOrder1(TreeNode<Type> *root)
	{
		stack<TreeNode<Type>*> s;
		TreeNode<Type>* p=root;
		while(p!=NULL||!s.empty())
		{
			while(p!=NULL)
			{
				s.push(p);
				p=p->lchild;
			}
			if(!s.empty())
			{
				p=s.top();
				//cout<<p->data<<" ";
				//s.pop();
				p=p->rchild;
				if(p==NULL)
				{
					p=s.top();
					cout<<p->data<<" ";
					s.pop();
					p=s.top();
					p=p->rchild;
				}
				
			}
		}
		
	}
	void InOrder1(TreeNode<Type> *root )
	{
		
		stack<TreeNode<Type> *> s;
        TreeNode<Type> *p=root;
        while(p!=NULL||!s.empty())
		{
			while(p!=NULL)
			{
				s.push(p);
				p=p->lchild;
			}
			if(!s.empty())
			{
				
				p=s.top();
				cout<<p->data<<" ";
				s.pop();
				/*if(!s.empty())
				{
                p=s.top();
                cout<<p->data<<" ";
				s.pop();
				}
				else    
				;*/
				p=p->rchild;
			}
		}
	}
	void PreOrder1(TreeNode<Type> *p )
	{
		if(p==NULL)
			return  ;
		
		stack<TreeNode<Type> *> st ;
		st.push(p);
		while(!st.empty())
		{
			st.pop();
			cout<<p->data<<"  ";
			
			if(p->rchild!=NULL)
			{
				st.push(p->rchild);
				if(p->lchild==NULL)
					p=p->rchild;
				else
				{
					st.push(p->lchild);
					p=p->lchild;
				}
				
			}
			else 
			{
				if(p->lchild==NULL)
				{ 
					if( !st.empty())
						p=st.top(); 	   
				}
				else
				{
					st.push(p->lchild);
					p=p->lchild;
				}
			}
			
			
		}
		
	} 
public:
	bool IsBalanced(TreeNode<Type>* pRoot, int *pDepth)
	{
		if (pRoot == NULL)
		{
			pDepth = 0;
			return true;
		}
		int left=0, right=0;
		cout << pRoot->data << "  ";
		if (IsBalanced(pRoot->lchild,&left)\
			&& IsBalanced(pRoot->rchild,&right))
		{
			//
			cout <<"-"<< pRoot->data << "- ";
			int diff = left - right;
			if (diff <= 1 && diff >= -1)
			{
				*pDepth = 1 + (left > right ? left : right);
				return true;

			}
		}
		return false;
	}

	bool IsBalanced(TreeNode<Type>* pRoot)
	{
		int depth = 0;
		return IsBalanced(pRoot,&depth);
	}
	void IsTest()
	{
		cout<<IsBalanced(root)<<endl;
	}

	int TreeDepth(TreeNode<Type>* pRoot)
	{
		if (pRoot == NULL)
		{
			return 0;
		}
		int nLeft = TreeDepth(pRoot->lchild);
		int nRight = TreeDepth(pRoot->rchild);
		return (nLeft > nRight) ? (nLeft + 1) : (nRight+1);
	}
	void _TreeDepthTest()
	{
		cout << TreeDepth(root) << endl;
	}
private:
	TreeNode<Type>* root;
   	Type         refvalue;
};
