//
// Created by zhengwei.
//

/*

标题：带分数

    100 可以表示为带分数的形式：100 = 3 + 69258 / 714

    还可以表示为：100 = 82 + 3546 / 197

    注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。

    类似这样的带分数，100 有 11 种表示法。

题目要求：
从标准输入读入一个正整数N (N<1000*1000)
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。
注意：不要求输出每个表示，只统计有多少表示法！


例如：
用户输入：
100
程序输出：
11

再例如：
用户输入：
105
程序输出：
6


资源约定：
峰值内存消耗 < 64M
CPU消耗  < 3000ms

请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

 */

//生成1~9这9个数字的全排列，先在可能的位置插入+，再在可能的位置插入/，验算等式，计数
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int parse(const char *arr, int pos, int len) {
    int ans = 0;
    int t = 1;
    for (int i = pos + len - 1; i >= pos; --i) {
        ans += (arr[i] - '0') * t;
        t *= 10;
    }
    return ans;
}

int main(int argc, const char *argv[]) {
    int n, ans = 0;
    scanf("%d", &n);
    std::string s = "123456789";
    do {
        const char *str = s.c_str();
        for (int i = 1; i <= 7; ++i) {//+号前的串的长度
//            string a = s.substr(0, i);
            int inta = parse(str, 0, i);
            if (inta >= n)break;

            for (int j = 1; j <= 9 - i - 1; ++j) {//+/两个符号之间的串的长度
//                string b = s.substr(i, j);
//                string c = s.substr(i + j);//这是/后面的串
//                int intb = atoi(b.c_str());//c_str()返回字符串首字符的地址
//                int intc = atoi(c.c_str());
                int intb = parse(str, i, j);
                int intc = parse(str, i + j, 9 - i - j);
                if (intb % intc == 0 && inta + intb / intc == n)ans++;
            }
        }
    } while (std::next_permutation(s.begin(), s.end()));
    printf("%d\n", ans);
    return 0;
}