#include"SeqList.h"

void InitSeqList(SeqList *list)
{
	list->capacity = SEQLIST_DEFAULT_SIZE;
	list->base = (ElemType*)malloc(sizeof(ElemType)*list->capacity);
	assert(list->base != NULL);
	list->size = 0;
}

int begin()
{return 0;}
int end(SeqList *list)
{return list->size;}

bool isempty(SeqList *list)
{return list->size == 0;}
bool isfull(SeqList *list)
{return list->size >= list->capacity;}

bool push_back(SeqList *list,ElemType x)
{
	return insert_pos(list,end(list),x);
}
bool push_front(SeqList *list,ElemType x)
{
	return insert_pos(list,begin(),x);
}
/*
bool push_back(SeqList *list,ElemType x)
{
	if(isfull(list))
		return false;
	list->base[list->size++] = x;
	return true;
}

bool push_front(SeqList *list,ElemType x)
{
	if(isfull(list))
		return false;
	
	for(int i=list->size; i>0; --i)
	{
		list->base[i] = list->base[i-1];
	}
	list->base[0] = x;

	list->size++;
	return true;
}
*/
bool pop_back(SeqList *list)
{
	if(isempty(list))
		return false;
	list->size--;
	return true;
}

bool pop_front(SeqList *list)
{
	if(isempty(list))
		return false;
	for(int i=0; i<list->size-1; ++i)
	{
		list->base[i] = list->base[i+1];
	}
	list->size--;
	return true;
}

bool insert_pos(SeqList *list, int p, ElemType x)
{
	if(isfull(list))
		return false;
	if(p<0 || p>list->size)
		return false;

	for(int i=list->size; i>p; --i)
	{
		list->base[i] = list->base[i-1];
	}
	list->base[p] = x;
	list->size++;
	return true;
}

bool delete_val(SeqList *list, ElemType key)
{
	int pos = find(list,key);
	if(pos == -1)
		return false;
	delete_pos(list,pos);
	return true;
}

/*
bool delete_val(SeqList *list, ElemType key)
{
	for(int i=0; i<list->size; ++i)
	{
		if(list->base[i] == key)
			break;
	}
	if(i >= list->size)
		return false;
	for(int k=i; k<list->size-1; ++k)
	{
		list->base[k] = list->base[k+1];
	}
	list->size--;
	return true;
}
*/
void show(SeqList *list)
{
	for(int i=0; i<list->size; ++i)
	{
		cout<<list->base[i]<<" ";
	}
	cout<<endl;
}