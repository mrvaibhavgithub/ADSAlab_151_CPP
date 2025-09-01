/*
Problem Statement:
Given an array arr[] of N positive integers which denotes 
the cost of selling and buying stock on each of the N days. 
The task is to find the maximum profit that can be earned 
by buying a stock on or selling all previously bought stocks on a particular day.
*/

#include <iostream>
using namespace std;

long long maxProfit(int arr[], int N) {
    long long profit = 0;
    int maxPrice = arr[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] <= maxPrice) {
            profit += (maxPrice - arr[i]);  // Buy at arr[i], sell at maxPrice
        } else {
            maxPrice = arr[i];  // Update future selling price
        }
    }
    return profit;
}

int main() {
    int N;
    cin >> N;
    int arr[1000];
    for (int i = 0; i < N; i++) cin >> arr[i];

    cout << maxProfit(arr, N) << endl;
    return 0;
}

/*
Sample Input:
5
1 3 1 2 5

Sample Output:
7
*/
