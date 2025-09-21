#include <iostream>
#include <string>
#include <vector>

int main(){
    int n, m, t;
    std::string a, b;
    std::cin >> n >> m >> t;
    std::cin >> a >> b;
    std::vector<std::vector<long long>> f(m + 1, std::vector<long long>(k + 1, 0));
    std::vector<std::vector<long long>> g(m + 1, std::vector<long long>(k + 1, 0));
    g[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        char a_char = a[i - 1];
        for(int j = 1; j >= t; --j){
            char b_char = b[j - 1];
            for(int l = t; l >= 1; --l){
                if (a_char == b_char) {
//两种情况，一种是在前一种情况的最后一个字串后面加入一个字符也就f，另一个就是这个字符没有用，需要最后一个单独作为一个字串
                    long long ways_ending_here = f[j - 1][l] + g[j - 1][l - 1];
                    f[j][l] = ways_ending_here;
                    g[j][l] += f[j][l];
                }else{
                    f[j][l] = 0;
                }
            }
        }
    }
}