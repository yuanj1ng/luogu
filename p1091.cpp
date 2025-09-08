#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> high(n);
    for(int i = 0; i < n; i++){
        std::cin >> high[i];
    }
    std::vector<int> dp_left(n,1);
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < i; j++){
            if(high[j] < high[i]){
                dp_left[i] = std::max(dp_left[j] + 1, dp_left[i]);
            }
        }
    }
    std::vector<int> dp_right(n,1);
    for(int i = n - 1; i >= 0; i--){
        for(int j= n - 1; j > i; j--){
             if(high[j] < high[i]){
                dp_right[i] = std::max(dp_right[j] + 1, dp_right[i]);
            }
        }
    }
    int max_len = 0;
    for(int i = 0; i < n; i++){
        max_len = std::max(dp_left[i] + dp_right[i] - 1, max_len);
    }
    std::cout << n - max_len << std::endl;
    return 0;
}