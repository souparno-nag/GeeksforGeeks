class Solution {
  public:
    int calculateMaxPoints(int day, int last, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (dp[day][last] != -1) return dp[day][last];
        if (day == 0) {
            int maxm = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    maxm = max(maxm, mat[0][task]);
                }
            }
            return dp[0][last] = maxm;
        }
        int maxm = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int point = mat[day][task] + calculateMaxPoints(day-1, task, mat, dp);
                maxm = max(maxm, point);
            }
        }
        return dp[day][last] = maxm;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return calculateMaxPoints(n-1, 3, mat, dp);
    }
};
// Time Complexity: O(n*4*3)
// Space Complexity: O(n*4)
