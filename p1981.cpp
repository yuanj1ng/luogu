#include <iostream>
#include <string>
#include <stack>
#include <cctype> // 需要这个头文件来使用 isdigit 函数

int main() {
    std::string str;
    std::cin >> str;

    // 如果输入为空，直接给一个有效输出并退出，防止崩溃
    if (str.empty()) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::stack<long long> nums; // 使用 long long 防止中间乘法结果溢出
    std::stack<char> opes;
    long long temp_num = 0;

    // 算法思路：乘法优先级高，遇到就先算。加法优先级低，先存起来最后算。
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];

        // 1. 如果当前字符是数字，就累加到 temp_num
        if (isdigit(c)) {
            temp_num = (temp_num * 10 + (c - '0'));
        }

        // 2. 如果遇到操作符，或者已经到达字符串的末尾
        //    这标志着一个完整的数字刚刚解析完毕，需要进行处理
        if (!isdigit(c) || i == str.length() - 1) {
            
            // 检查符号栈顶是否是 '*'
            if (!opes.empty() && opes.top() == '*') {
                // 如果是，说明优先级高，立即计算
                opes.pop(); // 弹出 '*'
                long long num_left = nums.top(); // 取出乘号左边的数
                nums.pop();
                
                long long result = (num_left * temp_num) % 10000;
                nums.push(result); // 将乘法结果压回栈中
            } else {
                // 如果不是乘号（即是加号或栈为空），直接把数字压栈
                nums.push(temp_num);
            }
            
            // 如果当前字符是操作符 (即还没到字符串末尾)，则将其压入操作符栈
            if (i < str.length()) {
                opes.push(c);
            }
            
            // 重置临时数字，为解析下一个数字做准备
            temp_num = 0;
        }
    }

    // 3. 循环结束后，所有乘法都已计算完毕，栈里只剩下加法
    //    将所有数字从栈中取出相加
    long long final_result = 0;
    while (!nums.empty()) {
        final_result = (final_result + nums.top()) % 10000;
        nums.pop();
    }

    std::cout << final_result << std::endl;

    return 0;
}