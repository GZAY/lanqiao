#include<iostream>
#include<algorithm>
using namespace std;
/*
直接插入排序

*/

void zhijie_sort(int s[], int len){
	int t,i,j;
	for(i=1;i<len;i++)//i代表要插入数的下标
	{
		t=s[i];//存在临时变量里，也就是将要插入的数提出，与前面i-1个数进行比较
		for(j=i-1;j>=0;j--)//j代表i之前要遍历的数的个数,遍历到第0个停止
		{
			if(s[j]>t)//只要比要插入的数大就
				s[j+1]=s[j];//将s[j]往后移，直到移到第一个
			else
				break;
		}
		s[j+1]=t;//因为循环完后j从0减为-1才出来所以要加一
	}
}
int main(){
	int s[]={64,2,0,8,6,999,7,0,-8,6,6,6,1,76,1,1};
	int length=sizeof(s)/sizeof(s[0]);
	//sort(s,s+length);
	zhijie_sort(s,length);
	for(int i=0;i<length;i++)
		cout<<s[i]<<" ";
	return 0;
}