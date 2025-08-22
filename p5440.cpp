#include<iostream>
#include<string>
#include<vector>
#include<map>


int month_day[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};


bool is_prime(long long n,std::map <long long, bool> &is_prime_memo){
    if(is_prime_memo.find(n) == is_prime_memo.end()){
        if(n <= 1){
            return is_prime_memo[n] = false;
        }
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                return is_prime_memo[n] = false;
            }
        }
        return is_prime_memo[n] = true;
    }else{
        return is_prime_memo[n];
    }    
}


bool is_leap(int year) {
    // 条件1: 能被4整除，但不能被100整除
    // 或者 (||)
    // 条件2: 能被400整除
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool judge_day(int day, const std::vector<bool> &is_prime_init){
    if(day<=31 && is_prime_init[day]){
        return true;
    }else return false;
}

bool judge_month_day(int day,int month, const std::vector<bool> &is_prime_init){
    if(month >= 1 && month <= 12){
        if(month_day[month] >= day && is_prime_init[month*100+day]){
            return true;
        }
    }
    return false;
}

bool judge_year_month_day(int year,int month, int day,std::map <long long, bool> &is_prime_memo){
    if(month == 2 && day == 29 && !is_leap(year)){
        return false;
    }
    if(!is_prime((long long)year*10000 + month *100 + day, is_prime_memo)){
        return false;
    }
    return true;
}


void dfs(std::string &current_str, int index, int &match_num, const std::string &original_str,std::map <long long, bool> &is_prime_memo, const std::vector<bool> &is_prime_init){
    if(index < 0){
        int year = std::stoi(current_str.substr(0, 4));
        int month = std::stoi(current_str.substr(4, 2));
        int day = std::stoi(current_str.substr(6, 2));
        if(!judge_year_month_day(year, month, day, is_prime_memo)){
            return;
        }
        match_num++;
        return;
    }
        if(index == 5){
            int day = std::stoi(current_str.substr(6, 2));
            if(!judge_day(day, is_prime_init)){
                return;
            }
        }
        if(index == 3){
            int month = std::stoi(current_str.substr(4, 2));
            int day = std::stoi(current_str.substr(6, 2));
            if(!judge_month_day(day,month,is_prime_init)){
                return;
            }
        }
        if(original_str[index] == '-'){
            for(int i=0; i<10;i++){
                current_str[index] = i + '0';
                dfs(current_str, index-1, match_num, original_str, is_prime_memo, is_prime_init);
            }
        }else {
            current_str[index] = original_str[index]; 
            dfs(current_str, index-1, match_num, original_str, is_prime_memo, is_prime_init);   
        }

}

void sieve(int n, std::vector<bool> &is_prime_vec) {
    is_prime_vec.assign(n + 1, true); // 全部初始化为 true
    is_prime_vec[0] = is_prime_vec[1] = false; // 0 和 1 不是质数
    for (int p = 2; p * p <= n; p++) {
        if (is_prime_vec[p]) { // 如果 p 是质数
            // 那么 p 的所有倍数都不是质数
            for (int i = p * p; i <= n; i += p)
                is_prime_vec[i] = false;
        }
    }
}

int main(){
    int t;
    std::cin >> t;
    std::map <long long, bool> is_prime_memo;
    std::vector<bool> is_prime_init(10000);
    sieve(9999,is_prime_init);
    for(int i=0; i<t; i++){
        std::string str;
        std::cin >> str;
        int match_num = 0;
        std::string original_str = str;
        dfs(str,7,match_num,original_str,is_prime_memo,is_prime_init);
        std::cout << match_num << std::endl;;
    }
    return 0;
}