//
// Created by zhengwei.
//

/*
快速排序

排序在各种场合经常被用到。
快速排序是十分常用的高效率的算法。

其思想是：先选一个“标尺”，
用它把整个队列过一遍筛子，
以保证：其左边的元素都不大于它，其右边的元素都不小于它。

这样，排序问题就被分割为两个子区间。
再分别对子区间排序就可以了。

下面的代码是一种实现，请分析并填写划线部分缺少的代码。
*/

#include <stdio.h>
//既然这道题是快速排序，那么做这道题应该想到，每一个函数的
//作用和每一个变量的作用，找到基准点。 
void swap(int a[], int i, int j)//交换位置 
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[], int p, int r)//分开，将小于 
{
    int i = p;//i是左边的数的哨兵 
    int j = r + 1;//r+ 再赋给j则，j现在并未指向最右一个，所以题中的意思是想让i先走，而不是两个一起走 
    int x = a[p];//基准数 
    while(1){
        while(i<r && a[++i]<x);//让i一直向右走，直到走到r ，并且走到比基准数大的停止 
        while(a[--j]>x);//让j一直走到 比基准数小的停止 
        if(i>=j) break;//当i与j相遇时，终止循环 
        swap(a,i,j);//未相遇，交换i与j指向数的位置 
    }
	swap(a,p,j);//因为j指向的是比基准数大的，所以将基准与j交换位置，这样基准的左右两边就分开了 
    return j;
}

void quicksort(int a[], int p, int r)
{//变量p应该是最左边的数，变量r是最右边的数 
    if(p<r){
        int q = partition(a,p,r);
        quicksort(a,p,q-1);//对小于基准数的部分进行排序 
        quicksort(a,q+1,r);//对大于基准数的部分进行排序 
    }
}

int main()
{
	int i;
	int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};
	int N = 12;

	quicksort(a, 0, N-1);

	for(i=0; i<N; i++) printf("%d ", a[i]);
	printf("\n");

	return 0;
}