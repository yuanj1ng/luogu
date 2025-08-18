#include <iostream>
#include <vector>
#include <algorithm>


void dfs(int idx, int end_idx, long long current_sum, int c, std::vector<int> &arr,std::vector<long long> &sum){
    if(idx == end_idx){
        sum.push_back(current_sum);
        return;
    }
    dfs(idx+1, end_idx, current_sum, c, arr, sum);
    if(current_sum + arr[idx] <= c){
        dfs(idx+1, end_idx, current_sum+arr[idx], c, arr,sum);
    }
}


int main(){
    int n, c;
    std::cin >> n >> c;
    std::vector<int> arr;
    for(int i=0; i<n; i++){
        int key;
        std::cin >> key;
        if(key <= c){
            arr.push_back(key);
        }else break;
    }
    int len = arr.size();
    int mid = len/2;
    std::vector<long long> sum_a, sum_b;
    dfs(0, mid, 0, c, arr, sum_a);
    dfs(mid, len, 0, c, arr, sum_b);
    std::sort(sum_b.begin(), sum_b.end());
    long long ans = 0;
    for(size_t i = 0; i < sum_a.size(); i++){
        long long remaining_capacity = c - sum_a[i];
        auto it = std::upper_bound(sum_b.begin(),sum_b.end(),remaining_capacity);
        if(it != sum_b.begin()){
            int max_sum = sum_a[i] + *(--it);
            if(ans < max_sum){
                ans = max_sum;
            }
        }
 
    }
    if(!sum_a.empty()){
        if(ans < sum_a.back()){
            ans = sum_a.back();
        }
    }
    if(!sum_b.empty()){
        if(ans < sum_b.back()){
            ans = sum_b.back();
        }
    }
    std::cout << ans << std::endl;
}