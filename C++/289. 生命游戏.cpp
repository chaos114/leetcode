class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        for(int  i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int live = 0;
                for(int y =  max(0,i - 1);y < min(m,i + 2);y++){
                    for(int x = max(0,j - 1);x < min(n,j + 2);x++){
                        live += board[y][x] & 1;
                    }
                }
                if(live == 3 || (live == 4 && board[i][j] == 1)) board[i][j] |= 0b10;
            }
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                board[i][j] >>= 1;
            }
        }
    }
};