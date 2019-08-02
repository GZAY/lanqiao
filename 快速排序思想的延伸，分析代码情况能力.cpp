#include <stdio.h>
#include<stdlib.h>
int quick_select(int a[], int l, int r, int k) {
	int p = rand() % (r - l + 1) + l;
	int x = a[p];//基准
	{int t = a[p]; a[p] = a[r]; a[r] = t;}//交换
	int i = l, j = r;//哨兵
	while(i < j) {//查找交换
		while(i < j && a[i] < x) i++;
		if(i < j) {
			a[j] = a[i];
			j--;
		}
		while(i < j && a[j] > x) j--;
		if(i < j) {
			a[i] = a[j];
			i++;
		}
	}
	a[i] = x;//归位基准
	p = i;


	//前面看不懂无所谓，，现在直接将数组改成有序简单数，直接按照现在的顺序理解
	//i-l+1就是第几个小的数
	if(i - l + 1 == k) return a[i];//k是第几位，i - l + 1=k,k就是第i位
	if(i - l + 1 < k) return quick_select(a,i+1,r,k-(i - l + 1 ) ); //填空，由下面的情况分析，我们应该是从i的后一位，到最右边，第k-(i - l + 1 )小
	else return quick_select(a, l, i - 1, k);//从这看，if(i - l + 1 > k)则从最左边开始到i的前一位，第k小
}
	
int main()
{
	int a[] = {1,2,3,4,5,7,8,9};
	printf("%d\n", quick_select(a, 0, 7, 5));
	return 0;
}