/*
Problem Statement:
Given a number n, find the smallest number whose factorial contains at least n trailing zeroes.
*/

#include <bits/stdc++.h>
using namespace std;

long long countZeroes(long long x) {
    long long count = 0;
    while (x >= 5) {
        x /= 5;
        count += x;
    }
    return count;
}

long long findSmallestNumber(long long n) {
    long long low = 0, high = 5 * n;
    long long ans = -1;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (countZeroes(mid) >= n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    long long n;
    cin >> n;
    cout << findSmallestNumber(n) << endl;
    return 0;
}

/*
Sample Input/Output:

Input:
6

Output:
25
*/

