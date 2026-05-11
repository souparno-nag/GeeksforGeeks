class Solution {
  public:
  int countSubsetsWithSumK (vector<int>& arr, int target) {
      int n = arr.size();
      vector<vector<int>> dp(n, vector<int>(target+1, 0));
      // base case for element 1
      dp[0][0] = 1;
      if (arr[0] <= target) dp[0][arr[0]] += 1;
      // build the table
      for (int ind = 1; ind < n; ind++) {
          for (int sum = 0; sum <= target; sum++) {
              int notPick = dp[ind-1][sum];
              int pick = (arr[ind] <= sum) ? dp[ind-1][sum-arr[ind]] : 0;
              dp[ind][sum] = pick + notPick;
          }
      }
      return dp[n-1][target];
  }
    int countPartitions(vector<int>& arr, int diff) {
        // diff = s1 - s2, where s1 is the sum of subset 1 and s2 is the sum of subset 2
        // s1 = totalSum - s2
        // So, diff = (totalSum - s2) - s2
        // diff = totalSum - 2 * s2
        // s2 = (totalSum - diff)/2
        int total = 0, n = arr.size();
        for (int i = 0; i < n; i++) total += arr[i];
        if ((total - diff) < 0 || (total - diff) % 2 != 0) return 0;
        int target = (total - diff)/2;
        return countSubsetsWithSumK(arr, target);
    }
};