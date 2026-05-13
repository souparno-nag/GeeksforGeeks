class Solution {
  public:
    int getMaxProfit(vector<int>& val, vector<int>& wt, int ind, int W, vector<vector<int>>& dp) {
        if (ind == 0) {
            int profit = 0;
            while (wt[ind] <= W) {
                profit += val[ind];
                W -= wt[ind];
            }
            return profit;
        }
        if (dp[ind][W] != -1) return dp[ind][W];
        int notPick = getMaxProfit(val, wt, ind-1, W, dp);
        int pick = (wt[ind] <= W) ? val[ind] + getMaxProfit(val, wt, ind, W-wt[ind], dp) : 0;
        return dp[ind][W] = max(pick, notPick);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        return getMaxProfit(val, wt, n-1, capacity, dp);
    }
};