## Tabulation

```cpp
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int> (n+1, 0));
        for (int len = 0; len <= n; len++) dp[0][len] = len * price[0];
        for (int i = 1; i < n; i++) {
            for (int len = 0; len <= n; len++) {
                int notTake = dp[i-1][len];
                int take = INT_MIN, rodLen = i+1;
                if (rodLen <= len) take = price[i] + dp[i][len-rodLen];
                dp[i][len] = max(take, notTake);
            }
        }
        return dp[n-1][n];
    }
};
```

## Space Optimized

```cpp
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1, 0), temp(n+1, 0);
        for (int len = 0; len <= n; len++) dp[len] = len * price[0];
        for (int i = 1; i < n; i++) {
            for (int len = 0; len <= n; len++) {
                int notTake = dp[len];
                int take = INT_MIN, rodLen = i+1;
                if (rodLen <= len) take = price[i] + temp[len-rodLen];
                temp[len] = max(take, notTake);
            }
            dp = temp;
        }
        return dp[n];
    }
};
```
