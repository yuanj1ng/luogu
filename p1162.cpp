#include <iostream>
#include <vector>
#include <queue>


void bfs(int start_r,int start_c, int n, std::vector<std::vector<int>>& grid){
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    std::queue<std::pair<int,int>> q;
    q.push({start_r,start_c});
    grid[start_r][start_c] = -1;
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        int r = current.first;
        int c = current.second;
        for(int i = 0; i < 4; i++){
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            if(next_r >= 0 && next_r < n && next_c >= 0 && next_c < n && grid[next_r][next_c] == 0){
                q.push({next_r,next_c});
                grid[next_r][next_c] = -1;
            }
        }
    }
}


int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n,std::vector<int>(n,0));
    for(int i = 0; i < n; i++){
        std::vector<int> row(n);
        for(int j = 0; j < n; j++){
            int key;
            std::cin >> key;
            row[j] = key;
        }
        graph[i] = row;
    }
    for(int i = 0; i < n; i++){
        if(graph[0][i] == 0 ){
            bfs(0,i,n,graph);
        }
        if(graph[n-1][i] == 0){
            bfs(n-1, i, n, graph);
        }
        if(graph[i][0] == 0){
            bfs(i,0,n,graph);
        }
        if(graph[i][n-1] == 0){
            bfs(i,n-1,n,graph);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] == 0){
                std::cout << "2 ";
            }else if(graph[i][j] == -1){
                std::cout << "0 ";
            }else{
                std::cout << "1 ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}