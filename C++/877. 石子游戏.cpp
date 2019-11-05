class Solution {
public:
    bool stoneGame(vector<int>& piles) {
       int len = piles.size();
        vector<vector<int>> mark(len,vector<int>(len,INT_MIN));
        return scores(piles,mark,0,len - 1) > 0;
    }
    int scores(vector<int>& piles,vector<vector<int>>& mark,int left,int right){
        if(left > right)  return 0;
        if(left == right) return piles[left];
        if(mark[left][right] > INT_MIN) return mark[left][right];
        mark[left][right]  = max(piles[left] - scores(piles,mark,left + 1,right),piles[right] - scores(piles,mark,left,right - 1));
        return mark[left][right];
    }
};

///dp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        vector<int> dp(piles.begin(),piles.end());
        for(int l = 2;l <= len;l++){
            for(int i = 0; i + l - 1 < len;i++){
                dp[i] = max(piles[i] - dp[i + 1],piles[i + l - 1] - dp[i]);
            }
        }
        return dp[0] > 0;
        
    }
};