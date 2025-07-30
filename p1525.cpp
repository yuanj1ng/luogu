#include <iostream>
#include <vector>
#include <algorithm>


struct Condition{
    int a;
    int b;
    int conflict_score;
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
    int n, m;
    std::cin >> n >> m;
    Union_find_set criminal(n*2);//罪犯1-m
    std::vector<Condition> arr(m);
    for(int i=0; i<m; i++){
        Condition con;
        std::cin >> con.a >> con.b >> con.conflict_score;
        arr[i] = con;
    } 
    std::sort(arr.begin(), arr.end(), [](const Condition &a, const Condition &b){
        return a.conflict_score > b.conflict_score;
    });
    //按冲突分排序，优先把冲突大的分开放
    for(size_t i = 0; i < m; i++){
        int a = arr[i].a;
        int b = arr[i].b;
        //判断a和b是不是已经是朋友 也就是必须分到一起
        if(criminal.find(a) == criminal.find(b)){
            std::cout << arr[i].conflict_score << std::endl;
            return 0;
        }
        else{
            criminal.union_merge(a ,b+n); //把a和b的朋友合并
            criminal.union_merge(b ,a+n); //把b和a的朋友合并
        }
    }
    std::cout << 0 << std::endl;
    return 0;
}