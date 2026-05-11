class Solution {
  public:
    int countSubsetWithSumK (vector<int>& arr, int target) {
        int n = arr.size();
        // define dp
        vector<vector<int>> dp (n, vector<int> (target + 1, 0));
        // Base case for first element
        dp[0][0] = 1;                     // empty subset
        if (arr[0] <= target) {
            dp[0][arr[0]] += 1;           // subset containing only arr[0]
        }
        // build the table
        for (int ind = 1; ind < n; ind++) {
            for (int sum = 0; sum <= target; sum++) {
                int notPick = dp[ind-1][sum];
                int pick = 0;
                if (arr[ind] <= sum) pick = dp[ind-1][sum-arr[ind]];
                dp[ind][sum] = pick + notPick;
            }
        }
        return dp[n-1][target];
    }
    int perfectSum(vector<int>& arr, int target) {
        return countSubsetWithSumK(arr, target);
    }
};