#include <iostream>
#include <vector>


void dfs(int row,std::vector<bool> &col_used, std::vector<bool> &diag1_used, std::vector<bool> &diag2_used, std::vector<int> &path, int &ans_num,int n){
    if(row > n){
        if (ans_num < 3){
            for(size_t i=0; i<n; i++){
            std::cout << path[i] << (i == n - 1 ? "" : " ");
            }
        std::cout << std::endl;
        }
        ans_num++;
        return;
    }
    for(int col = 1; col <= n; col++){
        if(!col_used[col] && !diag1_used[row - col + n] && !diag2_used[row + col]){
            col_used[col] = true;
            path.push_back(col);
            diag1_used[row + n - col] = true;
            diag2_used[col + row] = true;

            dfs(row+1,col_used,diag1_used,diag2_used,path,ans_num,n);

            path.pop_back();
            col_used[col] = false;
            diag1_used[row + n - col] = false;
            diag2_used[col + row] = false;
        }
    }
}

int main(){
    int n;
    std::cin >> n;
    int ans_num = 0;
    std::vector<bool> col_used(n+1, false);//用来记录哪一列已经被用过了
    std::vector<bool> diag1_used(2 * n + 1,false);//主对角线
    std::vector<bool> diag2_used(2 * n + 1,false);//副对角线
    std::vector<int> path;
    dfs(1,col_used,diag1_used,diag2_used,path,ans_num,n);
    std::cout << ans_num << std::endl;
    return 0;
}