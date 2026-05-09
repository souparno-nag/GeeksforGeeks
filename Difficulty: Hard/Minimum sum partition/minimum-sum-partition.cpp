class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // code here
        int n = arr.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += arr[i];
        }
        vector<vector<bool>> dp(n, vector<bool> (total+1, false));
        for (int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= total; target++) {
                bool notPick = dp[ind-1][target];
                bool pick = false;
                if (arr[ind] <= target) pick = dp[ind-1][target-arr[ind]];
                dp[ind][target] = pick || notPick;
            }
        }
        int minDiff = INT_MAX;
        for (int target = 0; target <= total; target++) {
            if (dp[n-1][target]) {
                int s1 = target;
                int s2 = total - target;
                minDiff = min(minDiff, abs(s1 - s2));
            }
        }
        return minDiff;
    }
};
