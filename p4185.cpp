#include <iostream>
#include <vector>
#include <algorithm>

struct Video_pair{
    int p;
    int q;
    long long r;
};

struct Question{
    long long k;
    int v;
    long long num;
    long long ans = 0;
};

class Union_find_set{
    private:
        std::vector<long long> parent;
        std::vector<long long> union_size;
        long long union_nums;

    public:
        Union_find_set(long long n) : parent(n + 1), union_size(n + 1), union_nums(n) {
            for(size_t i=0; i <= n; i++){
                parent[i] = i;
                union_size[i] = 1;
            }
        }
        
        long long find(long long data){
            if(parent[data] == data){
                return data;
            }
            else{
                return parent[data] = find(parent[data]);
            }
        }
        
        long long get_union_nums() {
            return union_nums;
        }

        long long get_size(long long data){
            long long root  = find(data);
            return union_size[root];
        }

        void union_merge(long long x,long long y){
            long long root_x = find(x);
            long long root_y = find(y);
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
    int n,q;
    std::cin >> n >> q;
    std::vector<Video_pair> arr(n-1);
    for(int i=0; i<n-1; i++){
        Video_pair v_p;
        std::cin >> v_p.p >> v_p.q >> v_p.r;
        arr[i] = v_p;
    }
    std::vector<Question> arr_q(q);
    for(int i=0; i<q; i++){
        Question que;
        std::cin >> que.k >> que.v;
        que.num = i;
        arr_q[i] = que;
    }
    std::sort(arr.begin(),arr.end(), [](const Video_pair &a, const Video_pair &b){return a.r > b.r;});
    std::sort(arr_q.begin(), arr_q.end(), [](const Question &a, const Question &b){return a.k > b.k;});
    size_t arr_i = 0;
    Union_find_set video(n);
    for(int i=0; i<q; i++){
        int k = arr_q[i].k;
        int v = arr_q[i].v; 
       while(arr_i < n - 1 && arr[arr_i].r >= k){
            video.union_merge(arr[arr_i].p, arr[arr_i].q);
            arr_i++;
        }
        arr_q[i].ans = video.get_size(v) - 1;
    }
    std::sort(arr_q.begin(), arr_q.end(), [](const Question &a, const Question &b){return a.num < b.num;});
    for(size_t i = 0; i < arr_q.size(); i++){
        std::cout << arr_q[i].ans << std::endl;
    }
    return 0;
}