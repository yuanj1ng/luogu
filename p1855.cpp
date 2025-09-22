#include <iostream>
#include <vector>
#include <algorithm>

struct Item{
    int money;
    int time;
};

int main(){
    int n, m, t;
    std::cin >> n >> m >> t;
    std::vector<Item> arr(n+1);
    for(int i=1; i<=n; i++){
        std::cin >> arr[i].money >> arr[i].time;
    }
    std::vector<std::vector<std::vector<int>>> dp(n+1,std::vector<std::vector<int>>(m+1,std::vector<int>(t+1,0)));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=1; k <= t; k++){
                if(j>=arr[i].money && k >= arr[i].time){
                    dp[i][j][k] = std::max(
                        dp[i-1][j-arr[i].money][k-arr[i].time] + 1,
                        dp[i-1][j][k]);
                }else{
                    dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
    }
    std::cout << dp[n][m][t] << std::endl;
    return 0;
}