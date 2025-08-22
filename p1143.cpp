#include <iostream>
#include <vector>
#include <queue>


void bfs(int start_x,int start_y, int n, int m, std::vector<std::vector<int>>& graph){
    int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2};
    int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};
    std::queue<std::pair<int,int>> q;
    q.push({start_x,start_y});
    graph[start_x][start_y] = 0;
    while(!q.empty()){
        auto current = q.front();
        q.pop();
        int r = current.first;
        int c = current.second;
        for(int i = 0; i < 8; i++){
            int next_x = r + dx[i];
            int next_y = c + dy[i];
            if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && graph[next_x][next_y] == -1){
                q.push({next_x,next_y});
                graph[next_x][next_y] = graph[r][c] + 1;
            }
        }
    }
}


int main(){
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    std::vector<std::vector<int>> graph(n,std::vector<int>(m,-1));
    bfs(x - 1, y - 1, n, m, graph);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}