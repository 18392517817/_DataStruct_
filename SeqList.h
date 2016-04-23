#ifndef _SEQLIST_H
#define _SEQLIST_H

#include<iostream>
#include<assert.h>
using namespace std;

#define ElemType int
#define SEQLIST_DEFAULT_SIZE 10

typedef struct SeqList
{
 	ElemType *base;
	size_t   capacity;
    size_t   size;

}SeqList;

int begin();
int end(SeqList *list);
void InitSeqList(SeqList *list);
bool isempty(SeqList *list);
bool isfull(SeqList *list);
bool push_back(SeqList *list,ElemType x);
bool push_front(SeqList *list,ElemType x);
bool pop_back(SeqList *list);
bool pop_front(SeqList *list);
bool insert_pos(SeqList *list, ElemType p, ElemType x);
bool insert_val(SeqList *list, ElemType p, ElemType i);
bool delete_pos(SeqList *list, ElemType key);
bool delete_val(SeqList *list, ElemType key);
bool find(SeqList *list,ElemType key );
bool getvalue(SeqList *list,ElemType value,ElemType i);
bool modify(SeqList *list,ElemType p, ElemType i);
bool clear(SeqList *list);
bool destroy(SeqList *list);
bool sort(SeqList *list);
bool resver(SeqList *list);
bool length(SeqList *list,ElemType count);
bool next(SeqList *list);
bool prio(SeqList *list);
void show(SeqList *list);



#endif