#include <iostream>
#include <vector>
#include <cmath>

int main(){
    int r;
    std::cin >> r;
    std::vector<std::vector<int>> num(r,std::vector<int>(r));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < i+1; j++){
            std::cin >> num[i][j];
        }
    }
    std::vector<std::vector<int>> dp(r,std::vector<int>(r,0));
    dp[0][0] = num[0][0];
    for (int i = 1; i < r; i++) {
        dp[i][0] = num[i][0] + dp[i-1][0];
        for(int j = 1; j < i; j++){
            dp[i][j] = num[i][j] + std::max(dp[i-1][j],dp[i-1][j-1]);
        }
        dp[i][i] = num[i][i] + dp[i-1][i-1];
    }
    int max_sum = 0;
    for (int j = 0; j < r; j++) {
        if (dp[r-1][j] > max_sum) {
            max_sum = dp[r-1][j];
        }
    }
    std::cout << max_sum << std::endl;

    return 0;
}