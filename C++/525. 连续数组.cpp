class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res;
        int sum = 0;
        unordered_map<int,int> mp;
        int count = 0;
        mp[0] = -1;
        for(int i = 0;i < nums.size();i++){
             sum += nums[i] == 0 ? -1 : 1;
             nums[i] = sum;
             if(mp.count(sum)) count = max(count,i - mp[sum]);
             else mp[sum] = i;
        }
        return count;
        
        
    }
};