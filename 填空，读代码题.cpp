﻿//
// Created by zhengwei.
//
/*
标题：取数位

求1个整数的第k位数字有很多种方法。
以下的方法就是一种。


// 求x用10进制表示时的数位长度
int len(int x){
	if(x<10) return 1;
	return len(x/10)+1;
}

// 取x的第k位数字
int f(int x, int k){
	if(len(x)-k==0) return x%10;
	return _____________________;  //填空
}

int main()
{
	int x = 23574;
	printf("%d\n", f(x,3));
}

对于题目中的测试数据，应该打印5。

请仔细分析源码，并补充划线部分所缺少的代码。

注意：只提交缺失的代码，不要填写任何已有内容或说明性的文字。
*/
#include <iostream>
using namespace std;
// 求x用10进制表示时的数位长度
int len(int x){
    if(x<10) return 1;
    return len(x/10)+1;
}

// 取x的第k位数字
int f(int x, int k){
    if(len(x)-k==0)//求最末一位
        return x%10;
//    不是求最末一位，去掉最末一位进行递归
    return f(x/10,k);  //填空，返回的是数据的个位，不是 
}

int main()
{
    int x = 23574;
    printf("%d\n", f(x,3));//先调试出第三位代表什么 
}
