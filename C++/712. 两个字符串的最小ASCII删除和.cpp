class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        vector<vector<long long>> res(len1 + 1,vector<long long>(len2 + 1,0));
        for(int i = 1;i <= len2;i++){
            res[0][i] = res[0][i - 1] + s2[i - 1];
        }
        for(int i = 1;i <= len1;i++){
            res[i][0] = res[i - 1][0] + s1[i - 1];
        }
        for(int i = 1;i <= len1;i++){
            for(int j = 1;j <= len2;j++){
                if(s1[i - 1] == s2[j - 1]) res[i][j] = res[i - 1][j - 1];
                else res[i][j] = min(res[i - 1][j] + s1[i - 1],res[i][j - 1] + s2[j - 1]);
            }
        }
        return res[len1][len2];
    }
};