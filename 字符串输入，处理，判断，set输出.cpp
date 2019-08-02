//
// Created by zhengwei.
//
/*
标题：日期问题

小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。
 令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。
 更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。

比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。

给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？

输入
----
一个日期，格式是"AA/BB/CC"。  (0 <= A, B, C <= 9)

输出
----
输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。

样例输入
----
02/03/04

样例输出
----
2002-03-04
2004-02-03
2004-03-02

资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。

*/

//1960年1月1日至2059年12月31日
//AA/BB/CC

#include <iostream>
#include <sstream>
#include <set>
using namespace std;

bool isleap(int y){//判断闰年 
	return (y%4==0&&y%100!=0)||y%400==0;
}

void i2s(int y,string &x )//整型转字符串 
{
	stringstream ss;
	ss<<y;
	ss>>x;
}

string f(int y,int m,int d)
{
	if(y>=60&&y<100) y=y+1900;
	else if(y>0&&y<60)y=y+2000;
	else return "";
	
	if(d<1||d>31) return "";
	if(m<1||m>12) return "";
	bool _isleap=isleap(y);
	switch(m)
	{
		case 2:
		if(_isleap&&d>29)return "";
		if(!_isleap&&d>28) return "";
		break;
		case 4:
		if(d>30)return "";break;
		case 6:
		if(d>30)return "";break;
		case 9:
		if(d>30)return "";break;
		case 11:
		if(d>30)return "";break;
		default:break;
	}
	string _y,_m,_d;
	i2s(y,_y);
	i2s(m,_m);
	i2s(d,_d);
	
	if(_m.length()==1)_m="0"+_m;//字符串相加用“” 
	if(_d.length()==1)_d="0"+_d;
	
	return _y+"-"+_m+"-"+_d;
}

int main(int argc, const char *argv[]) {
   string d;
   cin>>d;
   int a=0,b=0,c=0;
   a=(d[0]-'0')*10+(d[1]-'0');//字符串转数字减去一个用''引起来的数字 
   b=(d[3]-'0')*10+(d[4]-'0');
   c=(d[6]-'0')*10+(d[7]-'0');
   string case1=f(a,b,c);
   string case2=f(c,a,b);
   string case3=f(c,b,a);
   set<string> ans;
   if(case1!="") ans.insert(case1);
   if(case2!="") ans.insert(case2);
   if(case3!="") ans.insert(case3);
   for(set<string>::iterator iter=ans.begin();iter!=ans.end();iter++)
   	cout<<*iter<<endl;
    return 0;
}