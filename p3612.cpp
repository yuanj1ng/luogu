#include <iostream>
#include <string>

int solver(int len,long long n, long long current_length){
    long long mid = current_length/2;
    if(n<=len){
        return n;
    }
    if(n <= mid){ //n在左边 还是原来的位置
        return solver(len,n,mid);
    }else{ //n在右边 位置变成n-1
        if(n == mid+1){
            return solver(len,n-1,mid);//特殊情况，右边第一个是之前最后一个
        }else{
            return solver(len,n-mid-1,mid);
        }
    }
}

int main(){
    std::string s;
    long long N;
    std::cin >> s >> N;
    int len = s.size();
    long long temp = len;
    int exp = 1;
    while(N>temp){
        temp *= 2;
        exp++;
    }
    int ans = solver(len,N,temp);
    std::cout << s[ans-1] << std::endl;
    return 0;
}
