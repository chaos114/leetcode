class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        long kmod = 1000000007;
        unordered_map<int,long> mp;
        sort(A.begin(),A.end());
        for(int i= 0;i < A.size();i++){
            mp[A[i]] = 1;
            for(int j = 0;j < i;j++){
                if(A[i] % A[j] == 0 && mp.count(A[i] / A[j])){
                     mp[A[i]] += ((mp[A[j]] * mp[A[i] / A[j]]) % kmod);
                     mp[A[i]] %= kmod;
                    
                }
            }
        }
        int res = 0;
        for(auto it : mp){
            res += it.second;
            res %= kmod;
        }
        return res;
    }
};