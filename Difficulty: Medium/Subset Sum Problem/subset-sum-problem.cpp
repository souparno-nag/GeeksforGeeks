// Space Optimization
class Solution {
  public:
    bool checkSubsetSum(int sum, vector<int>& arr) {
        int n = arr.size();
        vector<bool> dp(sum+1, false);
        // define base case
        dp[0] = true;
        if (arr[0] <= sum) {
            dp[arr[0]] = true;
        }
        // form the nested loops
        for (int ind = 1; ind < n; ind++) {
            vector<bool> temp(sum+1, false);
            temp[0] = true;
            for (int target = 1; target <= sum; target++) {
                bool notTake = dp[target];
                bool take  = (arr[ind] <= target) ? dp[target-arr[ind]] : false;
                temp[target] = take || notTake;
            }
            dp = temp;
        }
        return dp[sum];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        return checkSubsetSum(sum, arr);
    }
};

// Tabulation
// class Solution {
//   public:
//     bool checkSubsetSum(int sum, vector<int>& arr) {
//         int n = arr.size();
//         vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
//         // define base case
//         for (int i = 0; i < n; i++) dp[i][0] = true;
//         dp[0][arr[0]] = true;
//         // form the nested loops
//         for (int ind = 1; ind < n; ind++) {
//             for (int target = 0; target <= sum; target++) {
//                 bool notTake = dp[ind-1][target];
//                 bool take  = (arr[ind] <= target) ? dp[ind-1][target-arr[ind]] : false;
//                 dp[ind][target] = take || notTake;
//             }
//         }
//         return dp[n-1][sum];
//     }
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         return checkSubsetSum(sum, arr);
//     }
// };

// Memoization
// class Solution {
//   public:
//     bool recursiveSubsetSum(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
//         if (target == 0) return true;
//         if (index == 0) return dp[index][target] = (arr[0] == target);
//         if (dp[index][target] != -1) return dp[index][target];
//         bool notTake = recursiveSubsetSum(index - 1, target, arr, dp);
//         bool take = false;
//         if (arr[index] < target) take = recursiveSubsetSum(index - 1, target - arr[index], arr, dp);
//         return dp[index][target] = take || notTake;
//     }
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         int n = arr.size();
//         vector<vector<int>> dp(n, vector<int> (sum+1, -1));
//         return recursiveSubsetSum(n-1, sum, arr, dp);
//     }
// };

// class Solution {
//   public:
//     bool recursiveSubsetSum(int index, int target, vector<int>& arr) {
//         if (target == 0) return true;
//         if (index == 0) return (arr[0] == target);
//         bool notTake = recursiveSubsetSum(index - 1, target, arr);
//         bool take = false;
//         if (arr[index] < target) take = recursiveSubsetSum(index - 1, target - arr[index], arr);
//         return take || notTake;
//     }
//     bool isSubsetSum(vector<int>& arr, int sum) {
//         return recursiveSubsetSum(arr.size()-1, sum, arr);
//     }
// };