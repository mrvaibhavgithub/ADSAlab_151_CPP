/*
Problem Statement:
Given an array task[] of size N denoting amount of work to be done for each task, 
find the minimum amount of work to be done on each day so that all the tasks 
can be completed in at most D days.
Note: On one day work can be done for only one task.
*/

#include <iostream>
using namespace std;

int minWork(int task[], int N, int D) {
    int maxTask = task[0], sum = 0;
    for (int i = 0; i < N; i++) {
        if (task[i] > maxTask) maxTask = task[i];
        sum += task[i];
    }
    for (int capacity = maxTask; capacity <= sum; capacity++) {
        int days = 1, work = 0;
        for (int i = 0; i < N; i++) {
            if (work + task[i] <= capacity) {
                work += task[i];
            } else {
                days++;
                work = task[i];
            }
        }
        if (days <= D) return capacity;
    }
    return sum;
}

int main() {
    int N, D;
    cin >> N >> D;
    int task[1000];
    for (int i = 0; i < N; i++) cin >> task[i];

    cout << minWork(task, N, D) << endl;
    return 0;
}

/*
Sample Input:
5 3
7 2 5 10 8

Sample Output:
14
*/
