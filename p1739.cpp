#include <iostream>
#include <string>


int main(){
    std::string str;
    std::cin >> str;
    int l_nums = 0;
    for(size_t i=0; i <str.size() ;i++){
        if(str[i] == '('){
            l_nums++;//左括号数量
        }
        else if(str[i]==')'){
            if(l_nums>=1){
                l_nums--;//匹配上一个左括号；
            }else{
                std::cout << "NO" << std::endl;
                return 0;
            }

        }else if(str[i] == '@'){
            break;
        }else continue;
    }
    if(l_nums == 0){
        std::cout << "YES" << std::endl;
    }
    else{
        std::cout << "NO" << std::endl;
    }   
    return 0;
}