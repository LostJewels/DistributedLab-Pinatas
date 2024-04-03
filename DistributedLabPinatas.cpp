#include <iostream>
#include <vector>

using namespace std;

int maxCandies(vector<int>& pinatas) {
    int n = pinatas.size();
    vector<int> dp(n, 0);

    // Base case: The first piñata will always give 1 candy
    dp[0] = 1;

    // Iterate through the piñatas
    for (int i = 1; i < n; i++) {
        int left = (i - 1 >= 0) ? pinatas[i - 1] : 1;
        int right = (i + 1 < n) ? pinatas[i + 1] : 1;
        dp[i] = max(dp[i - 1], left * pinatas[i] * right);
    }

    return dp[n - 1];
}

int main() {
    int n;
    cout << "Enter the number of pinatas: ";
    cin >> n;
    vector<int> pinatas;
    cout << "Enter the values of the pinatas (separated by spaces): ";
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        pinatas.push_back(value);
    }
    // Check if the number of entered values matches the specified number of pinatas
    if (pinatas.size() != n) {
        cout << "Error: The number of entered values does not match the specified number of pinatas." << endl;
        return 1;
    }
    cout << "Max candies: " << maxCandies(pinatas) << endl;
    return 0;
}