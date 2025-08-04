#include <iostream>
#include <vector>


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
    std::vector<std::vector<int>> graph(n);
    int a, b;
    for(size_t i = 0; i < m; i++){
        std::cin >> a >> b ;
        graph[a].push_back(b);
        graph[b].push_back(a);
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
    //这是最后输出的状态
    for(int i = 0; i < n; i++){
        if(is_destory[i] == false){
            for(size_t j = 0; j < graph[i].size(); j++){
                if(is_destory[graph[i][j]] == false){
                    planet.union_merge(i, graph[i][j]);
                }
            }
        }
    }
    ans[k] = planet.get_union_nums() - k;
    //一次次倒序回去
    for(size_t i = 0; i < k; i++){
        int remaining_destroyed = k - 1 - i;
        int current_planet = destory_planet[k-i-1];
        is_destory[current_planet] = false;
        for(size_t j = 0; j < graph[current_planet].size(); j++){
                if(is_destory[graph[current_planet][j]] == false){
                    planet.union_merge(current_planet, graph[current_planet][j]);
                }
        }
        ans[k-i-1] = planet.get_union_nums() - remaining_destroyed;
    }
    for(int i = 0; i <= k; i++){
        std::cout << ans[i] << std::endl;
    }
    return 0;
}