class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> prev(4, 0);
        prev[0] = max(mat[0][1], mat[0][2]);
        prev[1] = max(mat[0][0], mat[0][2]);
        prev[2] = max(mat[0][0], mat[0][1]);
        prev[3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
        for (int day = 1; day < n; day++) {
            vector<int> temp (4, 0);
            for (int last = 0; last < 4; last++) {
                temp[last] = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        temp[last] = max(temp[last], mat[day][task] + prev[task]);
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
};
// Time Complexity: O(N*4)
// Space Complexity: O(4)
