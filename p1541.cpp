#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> grade(n);
    std::vector<int> num_card(5,0);
    for(int i = 0; i < n; i++){
        std::cin >> grade[i];
    }
    for(int i = 0; i < m; i++){
        int card;
        std::cin >> card;
        if(card == 1) num_card[1]++;
        if(card == 2) num_card[2]++;
        if(card == 3) num_card[3]++;
        if(card == 4) num_card[4]++;
    }
    std::vector<std::vector<std::vector<std::vector<int>>>> dp(
    num_card[1] + 1, std::vector<std::vector<std::vector<int>>>(
    num_card[2] + 1, std::vector<std::vector<int>>(
    num_card[3] + 1, std::vector<int>(
    num_card[4] + 1, 0
))));
    dp[0][0][0][0] = grade[0];
    for(int c1 = 0; c1 <= num_card[1]; c1++){
       for(int c2 = 0; c2 <= num_card[2]; c2++){
            for(int c3 = 0; c3 <= num_card[3]; c3++){
                for(int c4 = 0; c4 <= num_card[4]; c4++){
                    int pos = c1*1 + c2*2 + c3*3 + c4*4;
                    int max_prev_score = 0;
                    // 【修正点3】安全地从4个可能的上一步状态转移
                    if (c1 > 0) max_prev_score = std::max(max_prev_score, dp[c1 - 1][c2][c3][c4]);
                    if (c2 > 0) max_prev_score = std::max(max_prev_score, dp[c1][c2 - 1][c3][c4]);
                    if (c3 > 0) max_prev_score = std::max(max_prev_score, dp[c1][c2][c3 - 1][c4]);
                    if (c4 > 0) max_prev_score = std::max(max_prev_score, dp[c1][c2][c3][c4 - 1]);
                    if (max_prev_score > 0) {
                       dp[c1][c2][c3][c4] = max_prev_score + grade[pos];
                    }
                }
            }
       }
    }
    std::cout << dp[num_card[1]][num_card[2]][num_card[3]][num_card[4]] << std::endl;
    return 0;
}