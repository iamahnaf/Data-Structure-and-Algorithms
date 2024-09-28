#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCoins(const vector<int>& coins, int amount) {
    int count = 0;
    vector<int> sortedCoins = coins;
    sort(sortedCoins.rbegin(), sortedCoins.rend());
    
    for (int coin : sortedCoins) {
        while (amount >= coin) {
            amount -= coin;
            count++;
        }
    }
    return (amount == 0) ? count : -1;
}