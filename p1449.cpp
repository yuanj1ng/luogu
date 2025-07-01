#include <iostream>
#include <string>

long long a[100];

int main(){ 
    std::string str;
    std::cin >> str;
    int nums = 0;//记录当前栈顶位置
    int temp_num = 0,num1,num2;//操作数1和2，以及中间值
    for(size_t i=0;i<str.size();i++){
        if(str[i]=='@'){
            std::cout << a[nums-1] << std::endl;
        }
        if(str[i]=='.'){
            a[nums] = temp_num;
            temp_num = 0;
            nums++;
        }else if(str[i]>=48 && str[i]<=57){//是数字
            temp_num = (str[i]-48) + temp_num*10;
        }else{//操作符
            switch (str[i]) {
                case '-': 
                    num2 = a[nums-1];
                    a[nums-1]=0;
                    nums--;
                    num1 = a[nums-1];
                    a[nums-1]=0;
                    nums--;
                    temp_num = num1-num2;
                    a[nums] = temp_num;
                    temp_num = 0;
                    nums++;
                    break;

                case '+':
                    num2 = a[nums-1];
                    a[nums-1]=0;
                    nums--;
                    num1 = a[nums-1];
                    a[nums-1]=0;
                    nums--;
                    temp_num = num1+num2;
                    a[nums] = temp_num;
                    temp_num = 0;
                    nums++;
                    break;

                case '*':
                    num2 = a[nums-1];
                    a[nums-1]=0;
                    nums--;
                    num1 = a[nums-1];
                    a[nums-1]=0;
                    nums--;
                    temp_num = num1*num2;
                    a[nums] = temp_num;
                    temp_num = 0;
                    nums++;
                    break;

                case '/':
                    num2 = a[nums-1];
                    a[nums-1]=0;
                    nums--;
                    num1 = a[nums-1];
                    a[nums-1]=0;
                    nums--;
                    temp_num = num1/num2;
                    a[nums] = temp_num;
                    temp_num = 0;
                    nums++;
                    break;
            }
        }
    }
    return 0;
}