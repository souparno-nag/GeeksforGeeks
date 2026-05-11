```cpp
class Solution {
  public:
    int countSubsetWithSumK (vector<int>& arr, int ind, int sum) {
        // define base case
        if (ind < 0) return (sum == 0) ? 1 : 0;
        // go through (define) all possibilities
        int notPick = countSubsetWithSumK(arr, ind - 1, sum);
        int pick = 0;
        if (arr[ind] <= sum) pick = countSubsetWithSumK(arr, ind - 1, sum - arr[ind]);
        // return sum of all possibilities
        return pick + notPick;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        return countSubsetWithSumK(arr, n-1, target);
    }
};
```

```cpp
class Solution {
  public:
    int countSubsetWithSumK (vector<vector<int>>& dp, vector<int>& arr, int ind, int sum) {
        // define base case
        if (ind < 0) return (sum == 0) ? 1 : 0;
        // check if value exists in dp
        if (dp[ind][sum] != -1) return dp[ind][sum];
        // go through (define) all possibilities
        int notPick = countSubsetWithSumK(dp, arr, ind - 1, sum);
        int pick = 0;
        if (arr[ind] <= sum) pick = countSubsetWithSumK(dp, arr, ind - 1, sum - arr[ind]);
        // return sum of all possibilities
        return dp[ind][sum] = pick + notPick;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return countSubsetWithSumK(dp, arr, n-1, target);
    }
};
```

```cpp
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
```
