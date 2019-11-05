class Solution {
public:
    vector<vector<int>> move = {{1,0},{0,1},{-1,0},{0,-1}};
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        vector<vector<int>> mark(row,vector<int>(col,0));
        map<int,int> mp;
        int index = 1;
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(mark[i][j] == 0 && grid[i][j] == 1){
                    dfs(grid,mark,i,j,row,col,index,mp);
                    index++;
                }
            }
        }
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(grid[i][j] == 0){
                    set<int> st;
                    for(int n = 0;n < 4;n++){
                        int nextx = move[n][0] + i;
                        int nexty = move[n][1] + j;
                        if(nextx < 0 || nextx >= row || nexty < 0 || nexty >= col || grid[nextx][nexty] == 0) continue;
                        st.insert(mark[nextx][nexty]);
                    }
                    int temp = 0;
                    auto it = st.begin();
                    while(it != st.end()){
                        temp += mp[*it];
                        it++;
                    }
                    res = max(res,temp + 1);
                }
            }
        }
        return res == 0 ? mp[1] : res;
        
    }
    void dfs(vector<vector<int>> &grid,vector<vector<int>> &mark,int x,int y,int row,int col,int index,map<int,int> &mp){
        if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0 || mark[x][y] != 0) return;
        mp[index]++;
        mark[x][y] = index;
        for(int i= 0 ;i < 4;i++){
            int nextx = x + move[i][0];
            int nexty = y + move[i][1];
            dfs(grid,mark,nextx,nexty,row,col,index,mp);
        }
        return;
    }
    
    
    
};