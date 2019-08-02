#include<iostream>

using namespace std;

void quick_sort(int s[],int left,int right)
{
	//传入三个参数 数组 开始结束点
	int i = left; //left和right在每一轮排序中是固定的，所以需要让i和j去遍历
	int j = right;
	int temp;
	int pivot = s[(left+right)/2];//基准点为当前数组的中间位置

	while(i<=j)//只要没有查找完，继续循环
	{
		//i和j开始遍历，分别找一个比基准大的和比基准小的
		while(s[i]<pivot)	i++;
		while(s[j]>pivot)  j--;
		//找到后如果满足仍在左右两边则交换位置
		if(i<=j)
		{
			temp=s[i];
			s[i]=s[j];
			s[j]=temp;

			i++;//交换完毕后继续查找
			j--;
		}
	}
	if(left<j)   quick_sort(s,left,j);//只要j没有到达最左边继续分段排序
	if(i<right)	 quick_sort(s,i,right);
}
int main(){
	int s[]={5,4,8,6,7,9,1,3,2,10};
	int length = sizeof(s)/sizeof(s[0]);
	quick_sort(s,0,length-1);
	for(int i=0;i<length;i++)
		cout<<s[i]<<" ";
	return 0;
}