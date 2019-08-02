#include<iostream>
#include<cstring> 
using namespace std;
//计算个位
int ge_wei(int a)
{
	if(a % 2 == 0)//偶数
		return (a * 2) % 10;//乘2保留个位
	else
		return (a * 2 + 5) % 10;//奇数，是乘以2加上5保留个位
}

//计算进位
int jin_wei(char* mod)
{
	char* level[] = {//多位数如果超过n/7，就要进n
		"142857",
		"285714",
		"428571",
		"571428",
		"714285",
		"857142"
	};

	char buf[7];
	buf[6] = '\0';
	strncpy(buf,mod,6);//将mod字符串拷贝到buff

	int i;
	for(i=5; i>=0; i--){
		int tr = strcmp(level[i], buf);//从后往前，依次取level中的串和buff比较
		if(tr<0) return i+1;
		while(tr==0){//buff和level[i]相同
			mod += 6;//往后偏移6位
			strncpy(buf,mod,6);//再拷贝6个字符到buff
			tr = strcmp(level[i], buf);//再比较
			if(tr<0) return i+1;//buf更大 
			if(tr>0)//buf更小
				return i;
		}
	}

	return 0;
}

//多位数乘以7//读函数关键一点是要多写注释
void f(char* s)//s代表多位数
{
	int head = jin_wei(s);//head代表s*7的进位
	if(head > 0) printf("%d", head);//如果有进位则将其输出

	char* mod = s;//让mod指向这个多位数开，拷贝字符串指针
	while(*mod){//字符串结尾为0，没有到末尾
		int a = (*mod-'0');//字符转数字
		int x = (ge_wei(a) /*算出个位*/+ jin_wei(mod+1)) % 10;//两者相加取个位
		printf("%d",x);
		mod++;//指针后移
	}

	printf("\n");
}

int main()
{//解题从main开读，遇到函数就读进去
	f("4285711");//传入字符串，字符串是以指针标记其起始地址，字符串指针可以++，而数组指针是常量不能++
	f("34553834937543");
	return 0;
}
