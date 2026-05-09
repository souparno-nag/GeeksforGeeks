class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // code here
        int n = arr.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += arr[i];
        }
        vector<bool> prev(total+1, false), curr(total+1, false);
        prev[arr[0]] = true;
        prev[0] = curr[0] = true;
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= total; target++) {
                bool notPick = prev[target];
                bool pick = false;
                if (arr[ind] <= target) pick = prev[target-arr[ind]];
                curr[target] = pick || notPick;
            }
            prev = curr;
        }
        int minDiff = INT_MAX;
        for (int target = 0; target <= total/2; target++) {
            if (curr[target]) {
                int s1 = target;
                int s2 = total - target;
                minDiff = min(minDiff, abs(s1 - s2));
            }
        }
        return minDiff;
    }
};
