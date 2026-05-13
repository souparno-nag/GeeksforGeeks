class Solution {
  public:
    struct Item {
        double value;
        double weight;
    };
    static bool comparator (Item a, Item b) {
        return ((a.value/a.weight) > (b.value/b.weight));
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<Item> items (n);
        for (int  i = 0; i < n; i++) {
            items[i].value = (double)val[i];
            items[i].weight = (double)wt[i];
        }
        sort(items.begin(), items.end(), comparator);
        double total = 0;
        for (int i = 0; i < n; i++) {
            if (items[i].weight < capacity) {
                total += items[i].value;
                capacity -= items[i].weight;
            } else {
                total += (items[i].value * capacity) / items[i].weight;
                break;
            }
        }
        return total;
    }
};
