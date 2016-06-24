#include<iostream>
using namespace std;
template<class T ,class Size >
class TA
{
	T _a;
};

void Test1()
{
	int a[5] = {1,2,3,4,5};
	int *ptr = (int*)(&a+1);//下一个对象的地址 a[5]

	cout << *(a + 1) << endl;//2   a[1]
	cout << *(ptr - 1) << endl;//5 
	cout << *(ptr-2) << endl;//4
}
void Test2()
{
 
	char *const p1 ="12";//指针常量
	char const* p2="wes";      //常量指针
	const char* const p4="abc";
	p1[1] = 'k';
	// *p1[1] = 'd'; 
	 

}
 
void RecverNum()
{
	int N;
	//cin >> N;
	while ((cin >> N)&&N != EOF)
	//while (scanf_s("%d", &N) != EOF)
	{

		if (N<1 || N>3000)
			return;

		int a[1024];
		int b;
		int i = 0;
		while (i++<N)
		{
			cin >> b;
			if (b % 2 == 0)
			{

				int count = 0;
				while (b)
				{
					pow(2, 3);
					int c = b % 2;
					b = b / 2;
					count += (c *pow(2, b));
				}
				a[i] = count;
			}
			else
			{
				a[i] = b;
			}
		}
		i = 0;
		while (i++ < N)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}

}
#include<string.h>
void GetMemory1(char *p, int num)
{
	p = (char*)malloc(num*sizeof(char));	
}
void GetMemory2(char **p, int num)
{
	*p = (char*)malloc(num*sizeof(char));
}
void GetMemory3(char *&p, int num)
{
	p = (char*)malloc(num*sizeof(char));
}
char* GetMemory4( int num)
{
	char*p = (char*)malloc(num*sizeof(char));
	return p;
}
void Test3()
{
	char *str1 = NULL;
	char *str2 = NULL;
	char *str3 = NULL;
	char *str4 = NULL;
	//GetMemory1(str1,10);
	
	GetMemory2(&str2,10);
	strcpy(str2,"hello");
	cout << str2 << endl;
	
	GetMemory3(str3, 10);
	strcpy(str3, "hello");
	cout << str3 << endl;

	str4=GetMemory4(10);
	strcpy(str4, "hello");
	cout << str4 << endl;
	//free(str1);
	free(str2);
	free(str3);
	free(str4);
	//str1 = NULL;
	str2=str3=str4 = NULL;
}
void Test4()
{
	char  str[30];
	//gets(str);
	//puts(str);

	int a = 12;
	//string str;
	_itoa(a,str,10);
	cout << str << endl;

}

const char *mystrstr(const char* src,const char*sub)
{
	const char *bp;
	const char *sp;

	if (src==NULL || sub==NULL)
	{
		return src;
	}

	while (*src)
	{
		bp = src;
		sp = sub;
		do
		{
			if (!*sp)
				return src;
		} while (*bp++ == *sp++);
		src+=1;
	}
	return NULL;
}
void Test5()
{

	char p[] = "32412345";
	char q[] = "34";

	const char *r = mystrstr(p,q);
	cout << r << endl;

}

void RecStr(char *src)
{
	char *start = src,*end=src,*ptr=src;

	while (*ptr++ != '\0')
	{
		if (*ptr == ' ' || *ptr == '\0')
		{
			end = ptr - 1;
			while (start < end)
			{
				swap(*start++,*end--);
			}

			start = end = ptr + 1;//指向下一个单词
		}
	}

	start = src, end = ptr - 2;//ptr-1 =='\0' ;ptr-2 指向最后一个单词
	while(start < end)
	{
		swap(*start++,*end--);
	}
}

void Test6()
{
	char src[] = "I am from yanan";
	cout << src << endl;
	RecStr(src);
	cout << src << endl;
}
#include<string>
void Test7()
{
	char s1[12] = "abcd";
	const char *s2 = "ss";

	//strcat(s1,s2);
	strcat(s1,"ass");
	 cout << s1 << endl;
}
int mystrcmp(const char *src,const char *dst)
{
	int ret = 0;
 	while (!(ret=*(unsigned char*)src-*(unsigned char *)dst)&& *dst)
	{
		++src;
		++dst;
	}
	if (ret < 0)
		ret = -1; 
	else if (ret>0)
		ret = 1;


	return ret;
}
void Test8()
{
	char str[10] = "1234567";
	char str1[10] = "1234567";
	char str2[10] = "12345678";
	char str3[10] = "1234566";

	int test1 = mystrcmp(str, str1);
	int test2 = mystrcmp(str, str2);
	int test3 = mystrcmp(str, str3);

	cout << "test1=" << test1 << endl;
	cout << "test2=" << test2 << endl;
	cout << "test3=" << test3 << endl;
}

char *commomstring(char *str1, char *str2)
{
	int i, j;
	char *shortstr, *longstr;
	char *substr;

	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	if (strlen(str1) <= strlen(str2))
	{
		shortstr = str1;
		longstr = str2;
	}
	else
	{
		longstr = str1;
		shortstr = str2;
	}

	if (strstr(longstr, shortstr) != NULL)
		return shortstr;

	substr = (char*)malloc(sizeof(char)*(strlen(shortstr) + 1));

	for (i = strlen(shortstr); i > 0; i--)
	{
		for (j= 0; j <=strlen(shortstr)-i; j++)
		{
			memcpy(substr,&shortstr[j],i);
			substr[i] = '\0';
			if (strstr(longstr, substr) != NULL)
				return substr;
		}
	}
	return NULL;
} 
void Test9()
{
	char *str1 = "abcdefgww";
	char *str2 = "accdecg";
	char *common = commomstring(str1,str2);
	cout << common << endl;
}

char *get2String(long num)
{
	int i = 0;
	char *buffer;
	char *temp;

	buffer = (char*)malloc(33);
	temp = buffer;
	for (i = 0; i < 32; i++)
	{
		temp[i] = num&(1<<(31-i));
		temp[i] = temp[i] >> (31-i);
		temp[i] = (temp[i] == 0) ? '0' : '1';
	}
	buffer[32] = '\0';

	return buffer;
}
void Test10()
{
	char *p = NULL;
	int num = 123;
	cout <<"10进制：" <<num << endl;
	p = get2String(num);
	cout << "2进制：" << p << endl;

}
char * myreverse(  char * str,int len)
{
	if (len <= 1)
		return str;

	char t = *str;
	*str = (char)*(str+len-1);//
	*(str + len - 1) =(char) t;
	//swap(*str,*(str+len-1));
	 
 	return (myreverse(str+1,len-2)-1);
}
void Test11()
{
	char *str = "123456";
	cout << str << endl;

	char*str1 = myreverse(str,strlen(str));
	cout << str1 << endl;
}

char * mystrcat(char *dest,const char *src)
{
	char *ret = dest;
	while (*dest++);
	dest--;			// '\0'
	while (*dest++ = *src++); //dest+=src;

	return ret;
}
void Test12()
{
	char dest[1024] = "hello ";//拥有足够空间可以容纳下src的内容
	char *src = "world!";
	mystrcat(dest,src);
	cout << "dest="<<dest << endl;
}

int gbk_strlen(const char *str)
{
	const char *p = str;
	while (*p)
	{
		if (*p < 0 && (*(p + 1)<0 || *(p + 1)>63))
		{
			str++;
			p += 2;
		}
		else
		{
			p++;
		}
	}
	return (p-str);
}
void Test13()
{
	char str[] = "abc你好123中国456";
	cout << "str="<<str << endl;
	cout << "gbk_strlen(str)=" << gbk_strlen(str) << endl;
	cout <<"strlen(str)=" <<strlen(str) << endl;
	cout << "sizeod(str)=" << sizeof(str) << endl;
}

//位运算与嵌入式编程
void Test14()
{
	cout << "sizeof(int)=" << sizeof(int) << endl;				//4
	cout << "sizeof(float)=" << sizeof(float) << endl;			//4
	cout << "sizeof(double)=" << sizeof(double) << endl;		//8
	cout << "sizeof(long)=" << sizeof(long) << endl;            //4
	cout << "sizeof(long long)=" << sizeof(long long) << endl;  //8
	int i = 5.01;
	float f = 5;
	
	printf("%f\n", 5);        //?
	printf("%f\n", (float)5); //5.000000
	printf("%lf\n", 5.01);    //5.010000
	printf("%f\n", f);        //5.000000

	printf("%d\n", 5.01);     //?
	printf("%d\n", i);        //5
}

 //C++面向对象
//#define public private  //正确，把public宏定义为private
class Animal
{
public:
	void MakeNoise(){ cout << "MakeNoise()" << endl; }

};
void Test15()
{
	Animal an;
	//an.MakeNoise();
}
class Test
{
public:
	Test(){}
	//潜在的二义性
	//Test(char *Name, int len = 0){}
	Test(char *Name, int len){}
	Test(char*Name){}
};

struct CLS
{
	int m_i;
	CLS(int i):m_i(i)
	{
		//在栈上生成一个临时对象，
		//CLS();//互相调用将会栈溢出，而非死循环，
		cout << "CLS(int):this=" << this << endl;
	}
	CLS()
	{
		CLS(0);//调用了CLS(int i);但是并没有给m_i初始化
		cout << "CLS():this=" << this << endl;

	}
};
void Test16()
{
	CLS obj;
	cout << "&obj" << &obj << endl;
	cout << obj.m_i << endl; //不是0

}

void a_b(int a,int b)
{
	cout << "a="<<a << "b=" << b << endl;
}
void Test17()
{
	int a = 1;
	//printf("%d  %d\n",a++,++a);
	cout << a++ << " " << ++a << endl;
	 a = 0;
	cout << a++ << a++ << a++ << endl;
	int c = 1;
	a_b(c++,++c);
}


int main()
{ 

	Test17();
	//Test16();
	//Test15();
	//Test14();
	//Test13();
	//Test12();
	//Test11();//?未解决
	//Test10();
	//Test9();
	//Test8();
	//Test7();
	//Test6();
	//Test5();
	//Test4();
	//Test3();
	//RecverNum();
	system("pause");
	return 0;

}




