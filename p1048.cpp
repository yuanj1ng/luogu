#include<iostream>
#include<vector>
#include<algorithm>

struct Item{
    int value;
    int weight;
};

int main(){
    int n, w;
    std::cin >> w >> n;
    std::vector<Item> arr(n+1);
    for(int i = 1; i <= n; i++){
        Item a;
        std::cin >> arr[i].weight >> arr[i].value;
    }
    std::vector<std::vector<int>> dp(n+1,std::vector<int>(w+1,0));
    for(int i = 1; i <= n; i++){
        for( int j = w; j >= 1; j--){
            if(j >= arr[i].weight){
                dp[i][j] = std::max(dp[i-1][j-arr[i].weight]+arr[i].value , dp[i - 1][j]);
            }else{
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    std::cout << dp[n][w] << std::endl;
    return 0;
}