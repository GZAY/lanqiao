//
// Created by zhengwei.
//
/*
标题：等差素数列

2,3,5,7,11,13,....是素数序列。
类似：7,37,67,97,127,157 这样完全由素数组成的等差数列，叫等差素数数列。
上边的数列公差为30，长度为6。

2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
这是数论领域一项惊人的成果！

有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：

长度为10的等差素数列，其公差最小值是多少？

注意：需要提交的是一个整数，不要填写任何多余的内容和说明文字。

*/
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
set<int>all;//set集合，弱排序，元素唯一

bool isPrime(LL t) {//判断是否是素数
    for (int i = 2; i < t / 2; ++i) {//从2开始依次枚举，到一半时仍不能整除则是素数
        if (t % i == 0)return false;
    }
    return true;
}

int f(LL a[], int n) {
    for (int i = 0; i < n; ++i) {//枚举首项
        LL first = a[i];
        for (int delta = 1; delta < a[n - 1] - first; ++delta) {//枚举公差，公差范围即第一个数加上公差就是最后一个数
			//枚举时进行判断
            int m = first;//拷贝第一个
            for (int j = 1; j < 10; ++j) {//枚举个数为10
                m += delta;//下一个就是前一项加10
                if (all.find(m) == all.end()) //每枚举一个项就判断，m不是素数就break，换一个公差
                    break;
                if (m > a[n - 1])break;//如果m比最后一项大
                if (j == 9)//已经找到10项，加了9次公差且未推出，
                    return delta;
            }
        }
    }
    return -1;//没有找到，不可能
}
const int N=5000;
LL a[N];
int main(int argc, const char *argv[]) {
    a[0] = 2;
    a[1] = 3;//将素数数组的0项和第一项赋值为2,3

    all.insert(2);//将2,3插入集合
    all.insert(3);

    int index = 2;//数组下标，从第三个开始
    LL t = 5;//第三个数为5
    while (index < N) {//下标未越界
        if (isPrime(t)) {//只要t是素数
            a[index++] = t;//将t放入a数组中
            all.insert(t);//并插入集合
        }
        t++;//向下遍历
    }//将素数分别放进数组和set集合中
    cout<<f(a, N)<<endl;//输出最小公差
    return 0;
}