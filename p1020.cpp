#include <iostream>
#include <vector>
#include <string>
#include <sstream> 

int main(){
    std::vector<int> h;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int key;
    while(ss >> key){
        h.push_back(key);
    }
    int len = h.size();
    std::vector<int> dp1(len, 1);
    std::vector<int> dp2(len, 1);
    int result1 = 1, result2 = 1;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < i; j++){
            if(h[i] <= h[j]){
                dp1[i] = std::max(dp1[i],dp1[j] + 1);
                result1 = std::max(dp1[i],result1);
            }
            if(h[i] > h[j]){
                dp2[i] = std::max(dp2[i],dp2[j] + 1);
                result2 = std::max(dp2[i],result2);
            }
        }
    }
    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;
    return 0;
}