#include <iostream>
//#include <algorithm>
#include <string>
//#include <vector>
#include <queue>
//#include <assert.h>
#include <Windows.h>
using namespace std;

#include "Heap.h"
#include "FileCompress.h"
#include "HuffmanTree.h"

//多益笔试题
int  Main_Test()
{
	for (int i = 0; i < 5;++i)
	{
		static int x = i;
	 
		cout << x;
	}
	return 0;
	//00000
}

class Fruit
{
public:
	  Fruit()
	{
		cout << "Fruit" << endl;
	}
	// ~Fruit()
	 virtual~Fruit()
	{
		cout << "~Fruit" << endl;
	}
	// void Fun()
		 virtual void Fun()
	{
		cout << "Fruit::Fun" << endl;
	}
};

class Apple :public Fruit
{
public:
	Apple()
	{
		cout << "Apple" << endl;
	}
	 ~Apple()
	{
		cout << "~Apple" << endl;
	}
	 void  Fun()
	{
		cout << "Apple::Fun" << endl;
	}
};

int Test1()
{
	Fruit ** list = new Fruit*[2];
	list[0] = new Fruit();
	list[1] = new Apple();//父，子
	list[0]->Fun();//
	list[1]->Fun();
	delete list[0];
	delete list[1];
	delete list;
	return 0;

}
int func(int n,int *s)
{
	(n > 1) && func(n - 1, s);
	*s += n;
	return 0;
}
void Test2()
{
	int n, s;
	n = 101;
	s = -1;
	func(n,&s);
	cout << s <<endl;


}
int main()
{
	Test2();
	//Main_Test();
	//Test1();
	//TestHeap();
	//TestHuffmanTree_P();
	//TestCompress();
	system("pause");
	return 0;
}