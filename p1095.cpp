#include <iostream>
#include <algorithm>

int main(){
    int m, s, t;
    std::cin >> m >> s >> t;
    int runner = 0, caster = 0, dp[t+1];
    dp[0] = 0;
    for(int i = 1; i <= t; i++){
        runner = dp[i-1] + 17;
        if(m >= 10){
            m -= 10;
            caster += 60; 
        }else{
            m += 4;
        }
        dp[i] = std::max(runner, caster);
        if(dp[i] >= s){
            std::cout << "Yes" << std::endl;
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl; 
    std::cout << dp[t] << std::endl;
    return 0;
}