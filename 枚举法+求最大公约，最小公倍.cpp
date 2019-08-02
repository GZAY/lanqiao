#include<iostream>
 
using namespace std;

int ans;
int gcd1(int x,int y)
{//辗转相除法递归求最大公约数 
	if(y==0)return x;
	return gcd1(y,x%y);
}
int gcd(int x,int y)
{
	while(y!=0)
	{	
		int t;
		t=x%y;
		x=y;
		y=t;
	}
	return x;
}
int main()
{
	int i,j,a,b;
	for(a=1;a<=9;a++)
	{
		for(b=1;b<=9;b++)
		{
		if(a==b)continue;
			for(i=1;i<=9;i++)
			{
				for(j=1;j<=9;j++)
		 		{
					if(i==j)continue;
					int g1=gcd(a*i,b*j);
					int g2=gcd(a*10+i,b*10+j);
					if(a*i/g1==(a*10+i)/g2&&b*j/g1==(b*10+j)/g2)
						ans++;
					
				}
			}
		}
	}
					
	cout<<ans<<endl;
	return 0;
}
