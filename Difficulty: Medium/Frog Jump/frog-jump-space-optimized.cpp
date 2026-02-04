class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        int prev1 = 0, prev2 = 0;
        for (int i = 1; i < n; i++) {
            int jumpOne = prev1 + abs(height[i] - height[i-1]);
            int jumpTwo = INT_MAX;
            if (i > 1) jumpTwo = prev2 + abs(height[i] - height[i-2]);
            int curr = min(jumpOne, jumpTwo);
            prev2 = prev1; prev1 = curr;
        }
        return prev1;
    }
};
