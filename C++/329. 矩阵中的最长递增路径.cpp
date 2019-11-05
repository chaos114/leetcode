class Solution {
public:
    vector<vector<int>> dis{{1,0},{0,1},{-1,0},{0,-1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int res = 0;
        vector<vector<int>> visited(row,vector<int>(col,0));
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                 res = max(res,find(i,j,row,col,matrix,visited));
            }
        }
        return res;
    }
    int find(int x,int y,int row,int col,vector<vector<int>> & matrix,vector<vector<int>> & visited){
        if(visited[x][y]) return visited[x][y];
        int cur = 1;
        for(int i = 0;i < 4;i++){
            int nextx = x + dis[i][0];
            int nexty = y + dis[i][1];
            if(nextx < 0 || nextx >= row || nexty < 0 || nexty >= col || matrix[nextx][nexty] <= matrix[x][y]) continue;
            cur = max(cur,find(nextx,nexty,row,col,matrix,visited) + 1);
        }
        visited[x][y] = cur;
        return cur;
    }
};