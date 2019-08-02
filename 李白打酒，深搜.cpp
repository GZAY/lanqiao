#include<iostream>
using namespace std;
int ans;
void f(int dian, int hua, int jiu)//函数参数依据题中变化的量来定
{
	if(dian==0&&hua==0&&jiu==1)ans++;//酒要等于1；每次开始酒的数量为1
	if(dian>0)f(dian-1,hua,jiu*2);//有条件的情况下去试探，然后寻找出口
	if(hua>0)f(dian,hua-1,jiu-1);
}
int main(int argc,const char* argv[]){
	f(5,9,2);
	cout<<ans<<endl;
	return 0;
}