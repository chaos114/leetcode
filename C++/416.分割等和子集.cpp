class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) return false;
        int sum = 0;
        for(int i : nums){
          sum += i;
        }
      if(sum % 2) return false;
      sum = sum / 2;
      vector<int> dp(sum + 1,false);
      dp[0] = true;
      for(int i = 0;i < nums.size();i++){
        for(int j = sum;j >= nums[i];j--){
          dp[j] = dp[j] || dp[j - nums[i]]; 
        }
      }
      return dp[sum];
    }
};