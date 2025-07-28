#include <iostream>
#include <vector>
#include <algorithm>

struct Road{
    int a;
    int b;
    int time;
};

class Union_find_set{
    private:
        std::vector<int> parent;
        std::vector<int> leaf_nums;
        int union_nums;

    public:
        Union_find_set(int n) : parent(n + 1), leaf_nums(n + 1), union_nums(n) {
            for(size_t i=0; i <= n; i++){
                parent[i] = i;
                leaf_nums[i] = 1;
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
                if(leaf_nums[root_x] > leaf_nums[root_y]){
                    parent[root_y] = root_x;
                    leaf_nums[root_x] = leaf_nums[root_x] + leaf_nums[root_y];
                }else{
                    parent[root_x] = root_y;
                    leaf_nums[root_y] = leaf_nums[root_x] + leaf_nums[root_y];
                }
            }
        }
};


int main(){
    int n,m;
    std::cin >> n >> m;
    std::vector<Road> arr(m);
    for(int i=0; i<m; i++){
        Road road;
        std::cin >> road.a >> road.b >> road.time;
        arr[i] = road;
    }
    std::sort(arr.begin(),arr.end(), [](const Road &x, const Road &y){
        return x.time < y.time;
    } );
    Union_find_set village_union(n);
    for(size_t i=0;i<m;i++){
        village_union.union_merge(arr[i].a, arr[i].b);
        int union_nums = village_union.get_union_nums();
        if(union_nums == 1){
            std::cout << arr[i].time << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}