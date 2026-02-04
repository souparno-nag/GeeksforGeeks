class Solution {
  public:
    int calculateMinCost(vector<int>& height, int index, vector<int>& dp) {
        if (index == 0) return 0;
        if (dp[index] != -1) return dp[index];
        int left = calculateMinCost(height, index - 1, dp) + abs(height[index] - height[index-1]);
        int right = INT_MAX;
        if (index > 1) right = calculateMinCost(height, index - 2, dp) + abs(height[index] - height[index-2]);
        dp[index] = min(left, right);
        return dp[index];
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        return calculateMinCost(height, n-1, dp);
    }
};
