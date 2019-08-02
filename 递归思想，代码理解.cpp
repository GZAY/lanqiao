//
// Created by zhengwei.
//
/*
抽签

X星球要派出一个5人组成的观察团前往W星。
其中：
A国最多可以派出4人。
B国最多可以派出2人。
C国最多可以派出2人。
....

那么最终派往W星的观察团会有多少种国别的不同组合呢？

下面的程序解决了这个问题。
数组a[] 中是每个国家可以派出的最多的名额。
程序执行结果为：
DEFFF
CEFFF
CDFFF
CDEFF
CCFFF
CCEFF
CCDFF
CCDEF
BEFFF
BDFFF
BDEFF
BCFFF
BCEFF
BCDFF
BCDEF
....
(以下省略，总共101行)

*/
#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024
/*
 * k=a数组的下标，
 * m代表人数，初始为5
 * b字符串*/
void f(int a[], int k, int m, char b[])//观察函数结构，猜测函数的作用，分清楚函数每一部分的作用，
	//因为函数有个出口，而且输出的数据有很多，没有循环输出，所以函数应该会以某种方式循环
	//理清每个参数的作用，从传入的值，以及它的变化来考虑
{
	int i,j;

	if(k==N){
		b[M] = 0;//字符串结尾的标志
		if(m==0) printf("%s\n",b);
		return;
	}

	for(i=0; i<=a[k]; i++){//试着将k国家，派出i人
		for(j=0; j<i; j++) b[M-m+j] = k+'A';//填充buf，有i人就填i个国家符号(k+'A')
		//递归的参数变化，根据出口的判断条件，并寻找参数在哪些位置发生了变化，如果其他位置没有发生变化，则一定是在要填的位置，
		//而且如果是多个参数要变化很可能就是递归，因为代码填空一定只填一句
		f(a,k+1,m-i,b);//递归的参数变化最有可能就是与循环变量挂钩
	}
}
int main()
{
	int  a[N] = {4,2,2,1,1,3};
	char b[BUF];
	f(a,0,M,b);
	return 0;
}