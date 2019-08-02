//
// Created by zhengwei.
//
/*

题目标题：翻硬币

    小明正在玩一个“翻硬币”的游戏。

    桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。

    比如，可能情形是：**oo***oooo

    如果同时翻转左边的两个硬币，则变为：oooo***oooo

    现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，
    最少要翻动多少次呢？
    我们约定：把翻动相邻的两个硬币叫做一步操作，那么要求：

程序输入：
两行等长的字符串，分别表示初始状态和要达到的目标状态。每行的长度<1000

程序输出：
一个整数，表示最小操作步数

例如：
用户输入：
**********
o****o****

程序应该输出：
5

再例如：
用户输入：
*o**o***o***
*o***o**o***

程序应该输出：
1




资源约定：
峰值内存消耗 < 64M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

 */

#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main(int argc, const char *argv[]) {
    string src;
    string target;
    getline(cin, src);
    getline(cin, target);
    int n = src.length();
    int ans=0;
    int start=-1;
    for (int i = 0; i < n; ++i) {
        if(src[i]!=target[i]){
            if(start==-1)//还没标记第一个位置
            {
                start=i;
            }else//第一个位置已经标记,现在已经找到了第二个位置
            {
                ans+=(i-start);
                start=-1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}