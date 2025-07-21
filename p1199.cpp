#include <iostream>
#include <vector>
#include <algorithm>

struct Value_pair{
    int value;
    int a;
    int b;
};

int main(){
    int n;
    std::cin >> n;
    std::vector<Value_pair> arr;
    std::vector<bool> arr_n;
    for(int i=0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            Value_pair value_pair;
            std::cin >> value_pair.value;
            value_pair.a =i;
            value_pair.b =j;
            arr.push_back(value_pair);
        }
    }
    std::sort(arr.begin(),arr.end(),[](Value_pair x,Value_pair y){
        return x.value > y.value;
    });
    //选择第一个的时候，需要选择值最大的选a还是b
    int a = arr[0].a, b = arr[0].b;
    int last_hunman,last_robot;
    for(size_t i=1;i<arr.size();i++){
        if(arr[i].a == a || arr[i].b == a){
            last_hunman = a;
        }
        if(arr[i].a == b || arr[i].b == b){
            last_hunman = b;
        }
    }
    arr_n[last_hunman] = true;
    int t = 0;//记录一下这个选择再arr中的位置
   
}