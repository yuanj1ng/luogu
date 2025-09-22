#include <iostream>
#include <vector>
#include <algorithm>

struct Item{
    int v;
    int w;
};

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<Item> arr(m+1);
    for(int i = 1; i <= m; i++){
        std::cin >> arr[i].v >> arr[i].w;
    }
    std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1, 0));
    for(int i = 1; i <= m ; i++){
        for(int j = 1; j <= n; j++){
            if(j >= arr[i].v){
                dp[i][j] = std::max(dp[i-1][j-arr[i].v] + arr[i].v*arr[i].w, dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    std::cout << dp[m][n] << std::endl;
}