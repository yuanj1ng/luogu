#include<iostream>
#include<vector>
#include<string>
#include<set>

using ull = unsigned long long;

int main(){
    int p = 131;
    int n;
    std::cin >> n;
    std::set<ull> unique_hashes;
    std::string str;
    for(int i=0; i<n;i++){
        std::cin >> str;
        ull hash_value = 0;
        for(char c : str){
           hash_value = hash_value * p +c;
        }
        unique_hashes.insert(hash_value);
    }
    std::cout << unique_hashes.size() << std::endl;
    return 0;
}