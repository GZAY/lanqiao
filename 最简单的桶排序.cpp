#include <iostream>
#include <algorithm>
using namespace std;
int s[20];
int main()
{
	
	int t;
	int i;
	int len = sizeof(s)/sizeof(s[0]);
	while(1)
	{
		scanf("%d",&t);
		int g=getchar();
		s[t]++;
		if(g=='\n') break;
	}
	for(i=0;i<len;i++)
	{
		while(s[i]!=0)
		{
		cout<<i;
		s[i]--;
		}
	}
	return 0;
}