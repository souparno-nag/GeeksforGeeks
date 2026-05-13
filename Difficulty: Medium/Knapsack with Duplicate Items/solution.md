## Tabulation

```cpp
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
        for (int w = 0; w <= capacity; w++) {
            int profit = 0, W = w;
            while (wt[0] <= W) {
                profit += val[0];
                W -= wt[0];
            }
            dp[0][w] = profit;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int w = 0; w <= capacity; w++) {
                int notPick = dp[ind-1][w];
                int pick = (wt[ind] <= w) ? val[ind] + dp[ind][w-wt[ind]] : 0;
                dp[ind][w] = max(pick, notPick);
            }
        }
        return dp[n-1][capacity];
    }
};
```

## Space Optimized

```cpp
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> dp(capacity+1, 0), curr(capacity+1, 0);
        for (int w = 0; w <= capacity; w++) {
            int profit = 0, W = w;
            while (wt[0] <= W) {
                profit += val[0];
                W -= wt[0];
            }
            dp[w] = profit;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int w = 0; w <= capacity; w++) {
                int notPick = dp[w];
                int pick = (wt[ind] <= w) ? val[ind] + curr[w-wt[ind]] : 0;
                curr[w] = max(pick, notPick);
            }
            dp = curr;
        }
        return dp[capacity];
    }
};
```
