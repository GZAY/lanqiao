#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
const int MaxN=10000;
int line;
int data[MaxN];//最大数据规模100*100
	//输入一行字符，将其中的数字提取出来并放进数组中
void s2i(string &str,int & num)//将字符串转换为数字
{//string to int 
	stringstream ss;
	ss<<str;
	ss>>num;
}
int main(int argc, const char * argv[])
{
	scanf("%d",&line);//输入行数，只要后面有读取缓冲区的操作就必须要用getchar吃掉换行符
	getchar();//吃掉换行符
	int index=0;
	for(int i=0;i<line;++i)
	{
		string s;
		getline(cin,s);//从屏幕读取一行字符并赋给s
		istringstream iss(s);//创建istringstream对象并同时初始化，使其和字符串s绑定
		string tmp;
		while(getline(iss,tmp,' '))//以空格为间隔符将iss中的字符串依次放入tmp中
		{
			s2i(tmp,data[index++]);//将获取到的tmp的字符串，转换为int类型放入data数组中，在不断循环
		}
	}
	//最终index就是数据的个数
	sort(data,data+index);
	
	int a,b;
	for(int i=1;i<index;i++)//从数组中的第一个数开始遍历,因为是比较的与其前一个数，所以不从第0个数开始
	{
		if(data[i]==data[i-1]+2)
			a=data[i]-1;//a为断号的数
			//printf("%d ",data[i]-1);
		if(data[i]==data[i-1])
			b=data[i];//b为重复的数据
			//printf("%d",data[i]);
	}
	printf("%d %d",a,b);
	return 0;
}