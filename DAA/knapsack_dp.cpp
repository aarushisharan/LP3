#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int profit;
    int wt;
};

void knapsack_dp(int capacity, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (items[i - 1].wt <= w) {
                dp[i][w] = max(items[i - 1].profit + dp[i - 1][w - items[i - 1].wt],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit: " << dp[n][capacity] << endl;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity: ";
    cin >> capacity;

    vector<Item> items(n);
    cout << "Enter each item's profit and weight:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " (profit weight): ";
        cin >> items[i].profit >> items[i].wt;
    }

    knapsack_dp(capacity, items);
    
    return 0;
}
