#include <iostream>
#include <vector>
#include <algorithm>


struct Interval{
    int front;
    int end;
};

int main(){
    int n;
    std::cin >> n;
    std::vector<Interval> arr(n);
    for(int i = 0; i< n; i++){
        std::cin >> arr[i].front >> arr[i].end;
    }
    std::vector<int> dp(n, 0);
    std::sort(arr.begin(),arr.end(),[](Interval &a, Interval &b){return a.end < b.end;});
    std::vector<int>  max_intrval_index(n ,-1);
    
    for(int i = 0; i < n; i++){
        int l = 0, r = i-1;
        int mid;
        int idx = -1;
        while(l <= r){
            mid = (l + r)/2;
            if(arr[mid].end >= arr[i].front){
                r = mid - 1;
            }else if(arr[mid].end < arr[i].front){
                l = mid + 1;
                idx = mid;
            }
        }
        max_intrval_index[i] = idx;
    }
    std::vector<int> max_dp_so_far(n, 0);
    dp[0] = arr[0].end - arr[0].front + 1;
    max_dp_so_far[0] = dp[0]
    for(int i = 1; i < n; i++){//先把i区间选上
        int len = arr[i].end - arr[i].front + 1; 
        dp[i] = len;
        if(max_intrval_index[i] != -1){
            dp[i] = max_dp_so_far[max_intrval_index[i]] + len;
        }
        max_dp_so_far[i] = std::max(max_dp_so_far[i - 1], dp[i]);
    }
    std::cout  <<  max_dp_so_far[n-1] << std::endl;
    return 0;
}