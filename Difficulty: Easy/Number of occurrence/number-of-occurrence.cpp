class Solution {
  public:
    int first(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high)/2;
            if (arr[mid] == x) {
                ans = mid;
                high = mid-1;
            } else if (arr[mid] < x) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
    int last(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n-1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high)/2;
            if (arr[mid] == x) {
                ans = mid;
                low = mid+1;
            } else if (arr[mid] > x) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        int lo = last(arr, target), fo = first(arr, target);
        if (fo == -1) return 0;
        return (lo - fo + 1);
    }
};
