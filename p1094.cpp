#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int w;
    std::cin >> w;
    int n;
    std::cin >> n;
    std::vector <int> prices(n);
    for(int i=0; i<n; ++i){
        int price;
        std::cin >> price;
        prices[i] = price;
    }
    std::sort(prices.begin(),prices.end(), [](int a, int b){
        return a < b; //按从小到大排序
    });
    int l = 0, r = n-1;
    int ans = 0;
    bool con=false;
    while(l <= r){
         ans++;
        if(prices[l]+prices[r]>w){
            r--;
        }else{
            l++,r--;
            if(l==r){
                ans++;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}