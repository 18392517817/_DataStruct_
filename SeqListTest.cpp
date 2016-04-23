#include<iostream>
#include"SeqList.h"
using namespace std;

void main()
{
	SeqList mylist;
	InitSeqList(&mylist);

	int select = 1;
	ElemType item;
	int pos;
	while(select)
	{
		cout<<"**********************************"<<endl;
		cout<<"* [1] push_back   [2] push_front *"<<endl;
		cout<<"* [3] show_seqlist[0] quit_system*"<<endl;
		cout<<"* [4] pop_back    [5] pop_front  *"<<endl;
		cout<<"* [6] insert_pos  [7] insert_val *"<<endl;
		cout<<"* [8] delete_pos  [9] delete_val *"<<endl;
		cout<<"* [10] find       [11]getvalue   *"<<endl;
		cout<<"* [12] modify     [13]clear      *"<<endl;
		cout<<"* [14] destroy    [15]sort       *"<<endl;
		cout<<"* [16] resver     [17]length     *"<<endl;
		cout<<"* [18] next       [19]prio       *"<<endl;
		cout<<"**********************************"<<endl;
		cout<<"请选择:>";
		cin>>select;
		switch(select)
		{
		case 1:
			cout<<"请输入要插入的数据(-1结束):>";
			while(cin>>item,item!=-1)
			{
				push_back(&mylist,item);
			}
			break;
		case 2:
			cout<<"请输入要插入的数据(-1结束):>";
			while(cin>>item,item!=-1)
			{
				push_front(&mylist,item);
			}
			break;
		case 3:
			show(&mylist);
			break;
		case 4:
			pop_back(&mylist);
			break;
		case 5:
			pop_front(&mylist);
			break;
		case 6:
			cout<<"请输入要插入的位置:>";
			cin>>pos;
			cout<<"请输入要插入的值:>";
			cin>>item;
			insert_pos(&mylist,pos,item);
			break;
		case 7:
            cout<<"请输入要插入下标的位置:>";
			cin>>pos;
			insert_val(&mylist,pos,item );
			break;
		case 8:
			cout<<"请输入要删除的值:>";
			cin>>item;
			delete_pos(&mylist,item);
			break;
		case 9:
			cout<<"请输入要插删除的值:>";
			cin>>item;
			delete_val(&mylist,item);
			break;
		case 10:
			break;
	 
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			break;

		default:
			break;
		}
	}
}