#include<iostream>
#include<vector>
#include <numeric>
#include <algorithm>


// 洞的坐标结构体
struct Hole {
    long long x, y, z; // 使用 long long 防止平方后溢出
};


class Union_find_set{
    private:
        std::vector<int> parent;
        std::vector<int> leaf_nums;
        int union_nums;
    public:
        Union_find_set(int n):parent(n+1),leaf_nums(n+1),union_nums(n){
            std::fill(leaf_nums.begin(),leaf_nums.end(),1);
            std::iota(parent.begin(),parent.end(),0);
        }
        
        int find(int data){
            if(parent[data] == data){
                return data;
            }else {
                return parent[data] = find(parent[data]);
            }
        }

        void union_merge(int x, int y){
            int root_x = find(x);
            int root_y = find(y);
            if(root_x != root_y){
                if(leaf_nums[root_x] > leaf_nums[root_y]){
                    parent[root_y] = root_x;
                    leaf_nums[root_x] += leaf_nums[root_y];
                    union_nums--;
                }else{
                    parent[root_x] = root_y;
                    leaf_nums[root_y] += leaf_nums[root_x];
                    union_nums--;
                }
            }
        }
};

long long get_dist_sq(const Hole& a, const Hole& b) {
    return (a.x - b.x) * (a.x - b.x) + 
           (a.y - b.y) * (a.y - b.y) + 
           (a.z - b.z) * (a.z - b.z);
}

int main(){
    int t;
    std::cin >> t;
    for(int t_case = 0; t_case < t; t_case++){
        int n, h, r;
        std::cin >> n >> h >> r;
        std::vector<Hole> arr(n);
        for(int j = 0; j < n; j++){
            Hole hole;
            std::cin >> hole.x >> hole.y >> hole.z;
            arr[j] = hole;
        }
        Union_find_set union_find_set(n+3);//n+1作为底部，n+2作为顶部
        for(size_t i=0;i<n;i++){
            if(arr[i].z <= r){
                union_find_set.union_merge(i, n+1);
            }
            if(arr[i].z + r >= h){
                union_find_set.union_merge(i, n+2);
            }
        }
        for(size_t i = 0; i < n; i++){
            for(size_t j = i+1; j < n; j++){
                if(get_dist_sq(arr[i],arr[j]) <= 4LL*r*r){
                    union_find_set.union_merge(i, j);
                }
            }
        }
        int root_bottom = union_find_set.find(n+1);
        int root_top = union_find_set.find(n+2);
        if(root_bottom == root_top){
            std::cout << "Yes" << std::endl;
        }else std::cout << "No" << std::endl;
    }
    return 0;
}