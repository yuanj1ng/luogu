#include<iostream>
#include<vector>
#include<algorithm>

struct Item{
    int w;
    int v;
};

int main(){
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<Item>> arr(101);
    int max_c = 0;
    for(int i=0; i<n; i++){
        int c;
        Item item;
        std::cin >> item.w >> item.v >> c;
        arr[c].push_back(item);
        max_c = std::max(max_c,c);
    }
    std::vector<long long> dp(m+1);
    for(int i=1; i<=max_c;i++){//组循环
        for(int j=m;j>=0;j--){//重量循环
            for(size_t k=0; k<arr[i].size(); k++){//物品循环
                if(j >= arr[i][k].w){
                    dp[j] = std::max(arr[i][k].v + dp[j-arr[i][k].w], dp[j]);
                }
            }
        }

    }
    std::cout << dp[m] << std::endl;
    return 0;
    
}