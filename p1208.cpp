#include <iostream>
#include <vector>
#include <algorithm>

struct Farmer{
    int price;
    int quantity;
};

bool cmp(Farmer a,Farmer b){
    return a.price<b.price;
}

int main(){
    long n;
    int m;
    std::cin >> n >> m; //需求的总量n，农民数量m；
    std::vector<Farmer> farmers(m);
    for(int i=0;i<m;i++){
        Farmer farmer;
        std::cin >> farmer.price >> farmer.quantity;
        farmers[i]=farmer;
    }
    std::sort(farmers.begin(),farmers.end(),cmp);
    long current_quantity = 0;
    long long total_price = 0;
    for(size_t i =0;i<farmers.size();++i){
        if(farmers[i].quantity+current_quantity >= n){
            long need = n-current_quantity;
            total_price +=  need*farmers[i].price;
            break;
        }else{
            current_quantity += farmers[i].quantity;
            total_price +=  farmers[i].quantity*farmers[i].price;
        }
    }
    std::cout << total_price << std::endl;
}