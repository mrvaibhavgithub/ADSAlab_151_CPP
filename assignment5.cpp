/*
Problem Statement:
Given two arrays S[] and E[] of size N denoting starting and closing time of the shops 
and an integer value K denoting the number of people, 
the task is to find out the maximum number of shops they can visit in total 
if they visit each shop optimally.

Conditions:
1. A shop can be visited by only one person.
2. A person cannot visit overlapping shops.
*/

#include <iostream>
using namespace std;

class Shop {
public:
    int start, end;
};

void sortShops(Shop shops[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (shops[j].end > shops[j + 1].end ||
               (shops[j].end == shops[j + 1].end && shops[j].start > shops[j + 1].start)) {
                Shop temp = shops[j];
                shops[j] = shops[j + 1];
                shops[j + 1] = temp;
            }
        }
    }
}

int maxShopsVisited(int S[], int E[], int N, int K) {
    Shop shops[1000];
    for (int i = 0; i < N; i++) {
        shops[i].start = S[i];
        shops[i].end = E[i];
    }

    sortShops(shops, N);

    int personEnd[1000];
    int usedPersons = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        bool assigned = false;
        for (int j = 0; j < usedPersons; j++) {
            if (personEnd[j] <= shops[i].start) {
                personEnd[j] = shops[i].end;
                count++;
                assigned = true;
                break;
            }
        }
        if (!assigned && usedPersons < K) {
            personEnd[usedPersons++] = shops[i].end;
            count++;
        }
    }
    return count;
}

int main() {
    int N, K;
    cin >> N >> K;
    int S[1000], E[1000];
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> E[i];

    cout << maxShopsVisited(S, E, N, K) << endl;
    return 0;
}

/*
Sample Input:
6 2
1 2 3 3 5 8
4 5 6 8 9 10

Sample Output:
6
*/
