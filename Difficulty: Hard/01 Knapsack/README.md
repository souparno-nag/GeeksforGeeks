# Problem

You are given n  objects, a knapsack of capacity  c, array v, and array w. The ith object has value v[i] and weight w[i].

Determine the maximum total value that you can get by selecting objects in such a manner that their sum of weights is not greater than the capacity c.

## Recursion

```cpp
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int knapsack(vector<int>& value, vector<int>& weight, int ind, int W) {
	// base case
	if (ind == 0) {
		if (weight[0] <= W) return value[0];
		else return 0;
	}
	// define all possibilities
	int notPick = knapsack(value, weight, ind-1, W);
	int pick = INT_MIN;
	if (weight[ind] <= W) pick = value[ind] + knapsack(value, weight, ind-1, W-weight[ind]);
	return max(pick, notPick);
}


int main() {
	int n, W;
	cin >> n >> W;
	vector<int> value(n), weight(n);
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> weight[i];
	cout << knapsack(value, weight, n-1, W);
	return 0;
}
```

## Memoization

```cpp
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int knapsack(vector<vector<int>>& dp, vector<int>& value, vector<int>& weight, int ind, int W) {
	// base case
	if (ind == 0) {
		if (weight[ind] <= W) return dp[ind][W] = value[0];
		else return dp[ind][W] = 0;
	}
	// check dp table
	if (dp[ind][W] != -1) return dp[ind][W];
	// define all possibilities
	int notPick = knapsack(dp, value, weight, ind-1, W);
	int pick = INT_MIN;
	if (weight[ind] <= W) pick = value[ind] + knapsack(dp, value, weight, ind-1, W-weight[ind]);
	return dp[ind][W] = max(pick, notPick);
}


int main() {
	int n, W;
	cin >> n >> W;
	vector<int> value(n), weight(n);
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> weight[i];
	vector<vector<int>> dp(n, vector<int> (W+1, -1));
	cout << knapsack(dp, value, weight, n-1, W);
	return 0;
}
```

## Tabulation

```cpp
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int knapsack(vector<int>& value, vector<int>& weight, int W) {
	int n = weight.size();
	// define dp table
	vector<vector<int>> dp (n, vector<int> (W+1, 0));
	// base case
	for (int i = weight[0]; i <= W; i++) dp[0][i] = value[0];
	// build dp table
	for (int ind = 1; ind < n; ind++) {
		for (int w = 0; w <= W; w++) {
			int notPick = dp[ind-1][w];
			int pick = INT_MIN;
			if (weight[ind] <= w) pick = value[ind] + dp[ind-1][w-weight[ind]];
			dp[ind][w] = max(pick, notPick);
		}
	}
	return dp[n-1][W];
}


int main() {
	int n, W;
	cin >> n >> W;
	vector<int> value(n), weight(n);
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> weight[i];
	cout << knapsack(value, weight, W);
	return 0;
}
```

## Space Optimized

```cpp
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int knapsack(vector<int>& value, vector<int>& weight, int W) {
	int n = weight.size();
	// define dp table
	vector<int> dp(W+1, 0), temp(W+1, 0);
	// base case
	for (int i = weight[0]; i <= W; i++) dp[i] = value[0];
	// build dp table
	for (int ind = 1; ind < n; ind++) {
		for (int w = 0; w <= W; w++) {
			int notPick = dp[w];
			int pick = INT_MIN;
			if (weight[ind] <= w) pick = value[ind] + dp[w-weight[ind]];
			temp[w] = max(pick, notPick);
		}
		dp = temp;
	}
	return dp[W];
}


int main() {
	int n, W;
	cin >> n >> W;
	vector<int> value(n), weight(n);
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> weight[i];
	cout << knapsack(value, weight, W);
	return 0;
}
```

## Further Optimised

```cpp
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int knapsack(vector<int>& value, vector<int>& weight, int W) {
	int n = weight.size();
	// define dp table
	vector<int> dp(W+1, 0);
	// base case
	for (int i = weight[0]; i <= W; i++) dp[i] = value[0];
	// build dp table
	for (int ind = 1; ind < n; ind++) {
		for (int w = W; w >= 0; w--) {
			int notPick = dp[w];
			int pick = INT_MIN;
			if (weight[ind] <= w) pick = value[ind] + dp[w-weight[ind]];
			dp[w] = max(pick, notPick);
		}
	}
	return dp[W];
}


int main() {
	int n, W;
	cin >> n >> W;
	vector<int> value(n), weight(n);
	for (int i = 0; i < n; i++) cin >> value[i];
	for (int i = 0; i < n; i++) cin >> weight[i];
	cout << knapsack(value, weight, W);
	return 0;
}
```
