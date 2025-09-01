/*
Problem Statement:
Given a number n, find the smallest number whose factorial contains at least n trailing zeroes.
Approach: Divide and Conquer (Binary Search)
*/

#include <iostream>
using namespace std;

long long countZeroes(long long x) {
    long long count = 0;
    while (x >= 5) {
        x /= 5;
        count += x;
    }
    return count;
}

long long solve(long long low, long long high, long long n) {
    if (low > high) return -1;
    long long mid = (low + high) / 2;
    long long zeros = countZeroes(mid);

    if (zeros >= n) {
        long long leftAns = solve(low, mid - 1, n); 
        return (leftAns == -1) ? mid : leftAns;
    } else {
        return solve(mid + 1, high, n);
    }
}

long long findSmallestNumber(long long n) {
    return solve(0, 5 * n, n);
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
