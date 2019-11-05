//dp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
       int len = s.size();
       vector<vector<int>> dp(len,vector<int>(len,0));
       for(int i = 0;i < len;i++){
           dp[i][i] = 1;
       }
       for(int i = 2;i <= len;i++){
           for(int j = 0;j < len - i + 1;j++){
               int left = j;
               int right = j + i - 1;
              
               int m1 = s[left] == s[right] ? dp[left + 1][right - 1] + 2 : dp[left + 1][right - 1];
               int m2 = max(dp[left + 1][right],dp[left][right - 1]);
               dp[left][right] = max(m1,m2);
               
           }
       }
       return dp[0][len - 1];
    }
};