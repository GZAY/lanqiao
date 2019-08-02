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
//宽度搜索用于寻找变化的次数，和状态转移的所有次数。深度搜索用于穷举所有的可能性。
typedef struct stateAndLevel {
    string str;
    int level;
} stateAndLevel;

queue<stateAndLevel> queue1;
set<string> set1;
int n;

int main(int argc, const char *argv[]) {
    string src;
    string target;
    getline(cin, src);
    getline(cin, target);
    n = src.length();
    stateAndLevel first = {src, 0};
    queue1.push(first);//队列的第一个元素就是原串

    while (!queue1.empty()) {
        //获取并弹出队列首部
        stateAndLevel &front = queue1.front();
        queue1.pop();

        string basicString = front.str;
//        如果队首元素和目标一致，可以终止程序
        if (basicString.compare(target) == 0) {
            cout << front.level << endl;//输出层次，也就是变化多少次到达了这个状态
            return 0;
        }
//        把已经处理过的字符串加入set中备查，避免往回翻的状态重复加入
        set1.insert(basicString);
//        模拟，依次翻转后加入队列中
        for (int i = 0; i < n - 1; ++i) {
            string buff;
            buff.insert(0, basicString);
//            拷贝之后，翻转i和i+1两个位置的字符
            if (buff[i] == '*')
                buff[i] = 'o';
            else
                buff[i] = '*';
            if (buff[i + 1] == 'o')
                buff[i + 1] = '*';
            else
                buff[i + 1] = 'o';
//            string s(buff);//字符数组转字符串
            if (set1.find(buff) == set1.end()) {
                stateAndLevel obj = {buff, front.level + 1};
                queue1.push(obj);
            }
        }
//        cout << queue1.size() << endl;
    }

//    cout << src << "\n" << target << endl;
    return 0;
}