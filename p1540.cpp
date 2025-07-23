#include<iostream>
#include<deque>

int main(){
    int m,n;
    std::cin >> m >> n;
    std::deque<int> q;
    int word_num, ans=0;
    for(int i=0; i < n; i++){
        std::cin >> word_num;
        bool find = false;
        for(size_t j=0; j<q.size(); j++){
            if(q[j] == word_num){
                find = true;
                break;
            }
        }
        if(!find){
            // 只要没找到，查询次数就必然加 1
            ans++;
            // 如果内存满了，就淘汰一个
            if(q.size() == m){
                q.pop_front();
            }
            // 最后，把新单词加进去
            q.push_back(word_num);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}