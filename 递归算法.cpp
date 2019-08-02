#include<iostream>
using namespace std;
int ans;
int f(int n, int step){//递归的判断条件从两个方面思考1.每一步题中的限制要求2.结束条件，临界条件
	//添加step参数的原因是题目中对步数有限制要求每次递归需要判断步数是否为偶数
	if(n<0)return 0;
	if(n==0&&step%2==0)//对每一种方法进行判断奇偶性
		ans++;
	f(n-1,step+1);
	f(n-2,step+1);//台阶数在减少，步数在增加，走法的不同，会影响步数的不同，同时走一步或两步的台阶数减少也不同
	return ans;
}
int main(){
	int n=39,step=0;
	f(n,step);
	cout<<ans<<endl;
}