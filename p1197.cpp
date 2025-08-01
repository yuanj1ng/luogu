#include <iostream>
#include <vector>

struct Pair{
    int a;
    int b;
};

class Union_find_set{
    private:
        std::vector<int> parent;
        std::vector<int> union_size;
        int union_nums;

    public:
        Union_find_set(int n) : parent(n + 1), union_size(n + 1), union_nums(n) {
            for(size_t i=0; i <= n; i++){
                parent[i] = i;
                union_size[i] = 1;
            }
        }
        
        int find(int data){
            if(parent[data] == data){
                return data;
            }
            else{
                return parent[data] = find(parent[data]);
            }
        }
        
        int get_union_nums() {
            return union_nums;
        }

        void union_merge(int x,int y){
            int root_x = find(x);
            int root_y = find(y);
            if(root_x != root_y){
                union_nums--;
                if(union_size[root_x] > union_size[root_y]){
                    parent[root_y] = root_x;
                    union_size[root_x] = union_size[root_x] + union_size[root_y];
                }else{
                    parent[root_x] = root_y;
                    union_size[root_y] = union_size[root_x] + union_size[root_y];
                }
            }
        }
};


int main(){
    int n, m, k;
    std::cin >> n >> m;
    std::vector<Pair> arr(m);
    int a, b;
    for(size_t i = 0; i < m; i++){
        Pair pair;
        std::cin >> pair.a >> pair.b ;
        arr[i] = pair;
    }

    std::cin >> k;
    std::vector<bool> is_destory(n,false);
    std::vector<int> destory_planet(k);
    for(size_t i = 0; i< k; i++){
        int planet;
        std::cin >> planet;
        is_destory[planet] = true;
        destory_planet[i] = planet;
    }
    std::vector<int> ans(k+1);
    Union_find_set planet(n);
    for(int j = k; j >=0; j--){
        if(j < k){
            is_destory[destory_planet[j]] = false;
        }
        for(size_t i = 0; i < m; i++){
            a = arr[i].a;
            b = arr[i].b;
            //如果ab都没被摧毁
            if(is_destory[a] != true && is_destory[b] != true){
                planet.union_merge(a, b);
            }
        }
        ans[j] = planet.get_union_nums() - j;
    }
    for(int i = k; i>=0; i--){
        std::cout << ans[i] << std::endl;
    }
    return 0;
}