#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void readData(const vector<string>& input,
              unordered_map<string, int>& mp,
              vector<int>& prices) {

    for (string s : input) {
        int pos = s.find(':');
        string date = s.substr(0, pos);
        int val = stoi(s.substr(pos + 1));

        mp[date] = val;
        prices.push_back(val);
    }
}

int getMaxProfit(const vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    int minVal = prices[0];
    int profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] < minVal) {
            minVal = prices[i];
        } else {
            int curr = prices[i] - minVal;
            if (curr > profit) {
                profit = curr;
            }
        }
    }
    return profit;
}

unordered_map<string, int> checkMovement(const vector<int>& prices) {
    unordered_map<string, int> mp;
    int n = prices.size();

    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            mp["up"]++;
        } else if (prices[i] < prices[i - 1]) {
            mp["down"]++;
        } else {
            mp["same"]++;
        }
    }
    return mp;
}

int main() {

    vector<string> stockInput = {
        "2026-01-01:100",
        "2026-01-02:105",
        "2026-01-03:102",
        "2026-01-04:110",
        "2026-01-05:108"
    };

    unordered_map<string, int> mp;
    vector<int> prices;

    readData(stockInput, mp, prices);

    int ans = getMaxProfit(prices);
    unordered_map<string, int> moves = checkMovement(prices);

    cout << "Max Profit: " << ans << endl;
    cout << "Price Movement:\n";

    for (auto it : moves) {
        cout << it.first << " : " << it.second << endl;
    }

    return 0;
}