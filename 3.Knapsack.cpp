#include <iostream>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[100], profit[100];

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit: ";
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[101][101] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (weight[i - 1] <= w) {
                int include = profit[i - 1] + dp[i - 1][w - weight[i - 1]];

                int exclude = dp[i - 1][w];

                dp[i][w] = max(include, exclude);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "\nMaximum Profit: "
        << dp[n][capacity];

    return 0;
}
