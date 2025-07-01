#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> h_v(n);
    for(int i=0;i<n;i++){
        int h;
        std::cin >> h;
        h_v[i]=h;
    }
    std::sort(h_v.begin(),h_v.end(),[](int a,int b){
        return a>b;//第一次跳最高的，从大到小排序
    });
    int l=0,r=n-1;
    bool con = true;//false代表l++,true代表 r--
    long long ans = 1LL * h_v[l] * h_v[l] ;
    while(l!=r){
        ans += 1LL * (h_v[l] - h_v[r]) * (h_v[l] - h_v[r]);
        if (con){
            l++;
            con = false;
        } 
        else {
            r--;
            con = true;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}