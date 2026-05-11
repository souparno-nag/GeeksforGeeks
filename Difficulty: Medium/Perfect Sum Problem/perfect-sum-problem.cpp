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

// class Solution {
//   public:
//     int countSubsetWithSumK (vector<int>& arr, int ind, int sum) {
//         // define base case
//         if (ind < 0) return (sum == 0) ? 1 : 0;
//         // go through (define) all possibilities
//         int notPick = countSubsetWithSumK(arr, ind - 1, sum);
//         int pick = 0;
//         if (arr[ind] <= sum) pick = countSubsetWithSumK(arr, ind - 1, sum - arr[ind]);
//         // return sum of all possibilities
//         return pick + notPick;
//     }
//     int perfectSum(vector<int>& arr, int target) {
//         int n = arr.size();
//         return countSubsetWithSumK(arr, n-1, target);
//     }
// };