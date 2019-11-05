class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int len = boxes.size();
        vector<vector<vector<int>>> dp(len,vector<vector<int>>(len,vector<int>(len,0)));
        return dfs(boxes,dp,0,len - 1,0);
    }
    int  dfs(vector<int>& boxes,vector<vector<vector<int>>>& dp,int l,int r,int k){
        if(l > r) return 0;
        while(l < r && boxes[r - 1] == boxes[r]) {--r;++k;}
        if(dp[l][r][k] > 0) return dp[l][r][k];
        dp[l][r][k] = dfs(boxes,dp,l,r - 1,0) + (k + 1) * (k + 1);
        for(int n = l;n < r;n++){
            if(boxes[n] == boxes[r]){
                dp[l][r][k] = max(dp[l][r][k],dfs(boxes,dp,l,n,k + 1) + dfs(boxes,dp,n + 1,r - 1,0));
            }
        }
        return dp[l][r][k];
        
    }
};