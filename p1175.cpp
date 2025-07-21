#include<iostream>
#include<string>
#include<stack>
#include<map>
#include<vector>

bool is_ope(char c){
    return c =='+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int calculate(int num1, int num2, char ope){
    switch(ope){
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        case '^': {
            int result = 1;
            for(int i = 0; i < num2; i++) {
                result *= num1;
            }
            return result;
        }
    }
    return 0;
}

void print_step(std::string ans){
    std::vector<std::string> tokens;
    for(size_t i=0; i < ans.size(); i++){
        tokens.push_back(std::string(1, ans[i]));
    }
    while(tokens.size()>1){
        for(size_t i = 0; i < tokens.size(); i++){
            if(tokens[i].size() == 1 && is_ope(tokens[i][0])){
                int num1 = stoi(tokens[i-2]);  // string to int 转换
                int num2 = stoi(tokens[i-1]);  
                char ope = tokens[i][0];  // 取字符串的第一个字符
                int result = calculate(num1,num2,ope);
                tokens[i-2] = std::to_string(result); 
                tokens.erase(tokens.begin() + i-1, tokens.begin() + i + 1);
                for(size_t j = 0; j < tokens.size(); j++){
                    std::cout << tokens[j] << " ";
                }
                std::cout << std::endl;
                break;
            }
        }
    }
}

int main(){
    std::string str;
    std::cin >> str;
    std::string ans;
    std::stack<char> opes;
    std::map<char,int> pro = {
        {'-',0},{'+',0},{'*',1},{'/',1},{'^',2}
    };
    for(size_t i =0;i<str.size();i++){
        if(str[i] >= '0' && str[i] <= '9'){
            ans += str[i];
        }else if(is_ope(str[i])){
            while(!opes.empty() && 
      opes.top() != '(' && 
      ((str[i] != '^' && pro[str[i]] <= pro[opes.top()]) || 
       (str[i] == '^' && pro[str[i]] < pro[opes.top()]))){
                ans += opes.top();
                opes.pop();
            }
            opes.push(str[i]);
        }else{
            if(str[i] == '('){
                opes.push(str[i]);
            }else if(str[i] == ')'){
                while(opes.top() != '('){
                    ans += opes.top();
                    opes.pop();
                }
                opes.pop();
            }
        }
    }
    while(!opes.empty()){
        ans += opes.top();
        opes.pop();
    }
    for(size_t i = 0;i < ans.size(); i++){
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    print_step(ans);
}

