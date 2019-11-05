class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        vector<vector<long long>> dp(len2 + 1,vector<long long>(len1 + 1,0));
        for(int i = 0; i<= len1;i++){
            dp[0][i] = 1;
        }
        for(int i = 1;i <= len2;i++){
            int cur = 0;
            for(int j = i;j <= len1;j++){
                if(t[i - 1] == s[j - 1]){
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                } 
                else dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[len2][len1];
    }
};