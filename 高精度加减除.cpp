//1.写出数字观察规律，每一项都是斐波拉契数列的前后两项的商，
//2.转为求斐波那契数列的n和n+1项，要用递推式而不是递归式。
//3.n取多少？再增加n，小数点后的101位没有变化
//4.不能用c语言定义的整数型直接运算，而要手工地写大数加法和除法（减法）
#include<iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int n=300;

string add(string a,string b)
{
	a=a.substr(a.find_first_not_of('0'));
	b=b.substr(b.find_first_not_of('0'));
	long long lenA=a.length();
	long long lenB=b.length();
	long long len=max(lenA,lenB)+10;
	//翻转便于从低位逐步求和
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string ans(len,'0');//初始化答案为len长，全部为字符0
	for(int i=0;i<lenA;++i)
	{
		ans[i]=a[i];
	}
	int tmp=0;
	for(int i=0;i<len;++i)//tmp是上一位相加后的进位
	{
		if(i<b.length())
			tmp+=(ans[i]-'0')+(b[i]-'0');//字符串转数字
		//若b为短的字符串，则b的所有位置加完后，只需要将a的值给tmp
		else
			tmp+=(ans[i]-'0');
		ans[i]=tmp%10+'0';
		tmp/=10;
	}
	reverse(ans.begin(),ans.end());
	return ans.substr(ans.find_first_not_of('0'));
}

int cmp(string a,string b)
{
	unsigned long i1=a.find_first_not_of('0');
	if(i1==string ::npos)a='0';
	else a.substr(i1);

	unsigned long i2=b.find_first_not_of('0');
	if(i2==string ::npos)b='0';
	else b.substr(i2);


	if(a.length()>b.length())return 1;
	else if(a.length()<b.length())return -1;
	else{//长度相等
		if(a<b)return -1;
		if(a>b)return 1;
		else return 0;
	}
}
//此处a一定大于b
string subtract(string a,string b)
{
//完整的减法里面，a可以小于b，这时及结果为负数，交换ab进行下面的代码
	//1.翻转
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	//2.按位做减法
	for(int i=0;i<b.length();++i)
	{
		if(a[i]>=b[i]){
			a[i]=a[i]-b[i]+'0';
		}else{
			int k=1;
			while(a[i+k]=='0'){
				a[i+k]='9';
				k++;
			}
			//这里可以保证i+k这一位上不是0
				a[i+k]=a[i+k]-'1'+'0';//数字转字符串
				a[i]=(a[i]-'0'+10)-(b[i]-'0')+'0';
		}
	}
	reverse(a.begin(),a.end());
	if(a.find_first_not_of('0')==string :: npos)return "0";
	return a.substr(a.find_first_not_of('0'));
}
	
void i2s(int num, string &str) {
    stringstream ss;
    ss << num;
    ss >> str;
}
	//除法转换成减法
string divide(string a,string b)
{
	//只考虑a<b的情况
	string ans="0.";//在末尾追加0；
		for(int i=0;i<101;++i)
		{
			a.append("0");
			int t=0;
			while(cmp(a,b)>=0)
			{
				a=subtract(a,b);//a>=b不停做减法
				t++;
			}
			string t_str;
			i2s(t,t_str);
			ans.append(t_str);
		}
		return ans;
}
int main(int argc, const char *argv[]){
	string a="1";
	string b="1";
	for(int i=3;i<=n;++i)
	{
		string tmp=b;
		b=add(a,b);
		a=tmp;
	}
	
	string ans = divide(a,b);
	cout<<ans<<endl;
	cout<<ans.length()-2<<endl;
	return 0;
}