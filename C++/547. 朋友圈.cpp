class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()) return 0;
        int ans = 0;
        int len = M.size();
        for(int i = 0;i < len;i++){
            if(!M[i][i]) continue;
            ans++;
            dfs(M,i,len);
        }
        return ans;
    }
    void dfs(vector<vector<int>>& M,int cur,int len){
        for(int i = 0;i < len;i++){
            if(!M[cur][i]) continue;
            M[cur][i] = M[i][cur] = 0;
            dfs(M,i,len);
        }
    }
};