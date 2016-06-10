#pragma once
#include<iostream>
using namespace std;

enum NodeType
{
	HEAD_TYPE,	// 头节点
	VALUE_TYPE,	// 值节点
	SUB_TYPE,	// 子表节点
};

struct GeneralListNode
{
	NodeType _type;			// 节点类型
	GeneralListNode* _next;

	union Common
	{
		char _value;
		GeneralListNode* _subLink;
	};

	Common _con;

	GeneralListNode(NodeType type = HEAD_TYPE, char value = '\0')
		:_type(type)
		,_next(NULL)
	{
		if (type == VALUE_TYPE)
		{
			_con._value = value;
			//_value = value;
		}
		else if(type == SUB_TYPE)
		{
			_con._subLink = NULL;
		}
	}
};

class GeneralList
{
private:
	GeneralListNode* _link;
public:
	GeneralList(const char* str)
		:_link(NULL)
	{
		_CreateGeneralList(_link, str);
	}

	GeneralList(const GeneralList& gl)
		//:_link(gl._link) //浅拷贝 
	{
		_link = _CopyGeneralList(gl._link);
	}

	//GeneralList& operator=(const GeneralList& gl)
	//{
	//	if (this != &gl)
	//	{
	//		_DestoryGeneralList(this->_link);
	//		this->_link = _CopyGeneralList(gl._link);
	//	}

	//	return *this;
	//}

	GeneralList& operator=(GeneralList gl)
	{
		swap(_link, gl._link);

		return *this;
	}

	~GeneralList()
	{
		_DestoryGeneralList(_link);
		_link = NULL;
	}

	void Print()
	{
		_Print(_link);
		cout<<endl;
	}

	int Size()
	{
		return _Size(_link);
	}

	int Depth()
	{
		return _Depth(_link);
	}

protected:
	bool _IsValueChar(char ch)
	{
		if ((ch >= '0' && ch <= '9')
			|| (ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void _CreateGeneralList(GeneralListNode*& link, const char*& str)
	{
		if (*str++ != '(')
		{
			cout<<"Invalid Str"<<endl;
			exit(-1);
		}
		
		// 头结点
		GeneralListNode* head = new GeneralListNode();
		//GeneralListNode* head = new GeneralListNode(HEAD_TYPE);
		link = head;
		
		GeneralListNode* begin = head;
		// 跳过 ( ,

		while(*str != '\0')
		{
			// 值节点
			if (_IsValueChar(*str))
			{
				GeneralListNode* valueNode = new GeneralListNode(VALUE_TYPE, *str);
				++str;
				begin->_next = valueNode;
				begin = begin->_next;
			}
			else if(*str == '(')
			{
				// 递归创建子表
				GeneralListNode* subNode = new GeneralListNode(SUB_TYPE);
				begin->_next = subNode;
				begin = begin->_next;

				_CreateGeneralList(subNode->_con._subLink, str);
			}
			else if(*str == ')')
			{
				//递归之后，递归返回
				++str;
				return;
			}
			else
			{
				// , 空格
				++str;
			}
		}
	}

	void _Print(GeneralListNode* link)
	{
		GeneralListNode* begin = link;
		while (begin)
		{
			if (begin->_type == HEAD_TYPE)
			{
				cout<<"(";
			}
			else if(begin->_type == VALUE_TYPE)
			{
				cout<<begin->_con._value;
				if (begin->_next)
				{
					cout<<",";
				}
			}
			else if(begin->_type == SUB_TYPE)
			{
				_Print(begin->_con._subLink);
				if (begin->_next)
				{
					cout<<",";
				}
			}

			begin = begin->_next;
		}

		cout<<")";
	}

	int _Size(GeneralListNode* head)
	{
		int size = 0;
		GeneralListNode* cur = head;
		while (cur)
		{
			if (cur->_type == VALUE_TYPE)
			{
				++size;
			}
			else if (cur->_type == SUB_TYPE)
			{
				size += _Size(cur->_con._subLink);
			}
			 

			cur = cur->_next;
		}

		return size;
	}

	int _Depth(GeneralListNode* head)
	{
		int depth = 1;
		GeneralListNode* cur = head;
		while (cur)
		{
			if (cur->_type == SUB_TYPE)
			{
				int subDepth = _Depth(cur->_con._subLink);
				if (subDepth + 1 > depth)
				{
					depth = subDepth + 1;
				}
			}

			cur = cur->_next;
		}

		return depth;
	}

	GeneralListNode* _CopyGeneralList(GeneralListNode* head)
	{
		
		GeneralListNode* newList = new GeneralListNode(HEAD_TYPE);
		GeneralListNode* cur = head->_next;
		
		GeneralListNode* begin = newList;
		while (cur)
		{
			if (cur->_type == VALUE_TYPE)
			{
				GeneralListNode* valueNode = new GeneralListNode(VALUE_TYPE, cur->_con._value);
				begin->_next = valueNode;
			}
			else if(cur->_type == SUB_TYPE)
			{
				GeneralListNode* subNode = new GeneralListNode(SUB_TYPE);
				begin->_next = subNode;

				subNode->_con._subLink = _CopyGeneralList(cur->_con._subLink);
			}

			begin = begin->_next;
			cur = cur->_next;
		}

		return newList;
	}

	void _DestoryGeneralList(GeneralListNode* head)
	{
		GeneralListNode* cur = head;
		while (cur)
		{
			if (cur->_type == SUB_TYPE)
			{
				_DestoryGeneralList(cur->_con._subLink);
			}
			
			GeneralListNode* del = cur;
			cur = cur->_next;
			delete del;
		}
	}

};

inline void Test1()
{
	// 空表
	const char* str1 = "()";
	GeneralList gl1(str1);
	gl1.Print();

	// 单层
	const char* str2 = "(a,b)";
	GeneralList gl2(str2);
	gl2.Print();

	// 带子表
	const char* str3 = "(a,b,(c,d))";
	GeneralList gl3(str3);
	gl3.Print();

	// 带空格
	const char* str4 = "(a, b, (c,d))";
	GeneralList gl4(str4);
	gl4.Print();

	// 多层嵌套
	const char* str5 = "(a,b,(c,d),(e,(f),h))";
	GeneralList gl5(str5);
	gl5.Print();

	cout<<"gl5:Size == "<<gl5.Size()<<endl;
	cout<<"gl5:Depth == "<<gl5.Depth()<<endl;
}

inline void Test2()
{
	// 多层嵌套
	const char* str1 = "(a,b,(c,d),(e,(f),h))";
	GeneralList gl1(str1);
	gl1.Print();

 	cout<<sizeof(GeneralListNode)<<endl;

	//拷貝
	GeneralList gl2(gl1);
	gl2.Print();

	const char* str3 = "(a,b)";
	GeneralList gl3(str3);
	gl3.Print();
	//赋值运算
	gl3 = gl1;
	gl3.Print();
}

void GeneralList_Test()
{
	Test1();
	Test2();
}


//
//struct TaskInfo
//{
//	int _id; //任务号
//	string _desc;//描述
//	string _other;//其他
//
//	int _Begin;
//};
////任务队列
//class TaskQuqueNode
//{
//	TaskInfo _info;
//	TaskQuqueNode * _next;
//
//};
//class  TaskQuque
//{
//public:
//	void PushBack( TaskInfo &info)
//	{
//		info._Begin = CheckTimeOutTask();
//	}
//
//	void PushFront(const TaskInfo &info)
//	{}
//	
//	void PopFront()
//	{}
//	
//	void GetFront()
//	{}
//
//	int GetTickCount()
//	{
//		return 0;
//	}
//	void CheckTimeOutTask()
//	{
//		while (1)
//		{
//			TaskQuqueNode* prev = _head;
//			if (prev == NULL)
//			{
//				continue;
//			}
//			TaskQuqueNode*cur = _head->_next;
//			while (cur)
//			{
//				int gap = GetTickCount();
//				gap /= 1000;
//				if (gap > 1800)
//				{
//					prev->_next = cur->_next;
//					PushFront(cur->_info);;
//					cur = cur->_next;
//					delete cur;
//				}
//			}
//		}
//	}
//private:
//	TaskQuqueNode * _head;
//};
//
//class ScheduleTask
//{
//public:
//	void Schedule()
//	{}
//	void Check()
//	{
//		 
//	}
//private:
//	TaskQuque _queue;
//
//};

