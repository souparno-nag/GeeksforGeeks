// User function Template for C++

class Solution {
  public:
    int maxPrice(vector<int> &price, int ind, int len, vector<vector<int>>& dp) {
        if (ind == 0) {
            return len * price[0];
        }
        if (dp[ind][len] != -1) return dp[ind][len];
        int notTake = maxPrice(price, ind-1, len, dp);
        int take = INT_MIN;
        int rodLen = ind+1;
        if (rodLen <= len) take = price[ind] + maxPrice(price, ind, len-rodLen, dp);
        return dp[ind][len] = max(take, notTake);
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return maxPrice(price, n-1, n, dp);
    }
};