class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int minSteps = INT_MAX;
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
                    minSteps = min(jump, minSteps);
                }
            }
            dp[i] = minSteps;
        }
        return dp[n-1];
    }
};
