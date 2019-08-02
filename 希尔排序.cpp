#include<iostream>
#include<algorithm>
using namespace std;
/*
希尔排序
分治思想，化大为小降低复杂度
*/

void shell_sort(int s[], int len){
	int i=0;
	int temp;
	int p;
	int n=len/2;
	while(n>0)
	{
		if(s[i]<s[i+n])
		{
			if((i+n+1)<len)
			i++;
			else
			{
				i=0;
				n=n/2;
			}
		}
		else if((i+n)>=len)
		{
			i=0;
			n=n/2;
		}
		else
		{
			temp=s[i];
			s[i]=s[i+n];
			s[i+n]=temp;
			p=i;
				while((s[i-n]>s[i])&&((i-n)>=0))
				{
					temp=s[i];
					s[i]=s[i-n];
					s[i-n]=temp;
					i=i-n;
				}
			i=p;
			i++;
		}
	}
}
int main(){
	int s[]={64,2,0,8,6,999,7,0,-8,6,6,6,1,76,1,1};
	int length=sizeof(s)/sizeof(s[0]);
	//sort(s,s+length);
	shell_sort(s,length);
	for(int i=0;i<length;i++)
		cout<<s[i]<<" ";
	return 0;
}