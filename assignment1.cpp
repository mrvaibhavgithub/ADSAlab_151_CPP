/*Implement a problem of number of zeroes. 
Statement: Given an array of 1s and 0s which has all 
1s first followed by all 0s? Find the number of 0s. 
Count the number of zeroes in the given array. 
Input: arr[] = {1, 1, 1, 1, 0, 0}     Output: 2 
Input: arr[] = {1, 0, 0, 0, 0}       Output: 4*/

#include<iostream>
using namespace std;

bool isValidBinaryArray(int arr[], int n) {
    bool zeroStarted = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0 && arr[i] != 1) {
            return false; 
        }
        if (arr[i] == 0) {
            zeroStarted = true;
        } else if (zeroStarted && arr[i] == 1) {
            return false; 
        }
    }
    return true;
}

void countZero(int arr[], int n) {
    int low = 0, high = n - 1;
    int firstZero = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == 0) {
            if (mid == 0 || arr[mid - 1] == 1) {
                firstZero = mid;
                break;
            } else {
                high = mid - 1;
            }
        } else {
            low = mid + 1;
        }
    }

    if (firstZero != -1) {
        cout << "Number of zeros: " << n - firstZero << endl;
    } else {
        cout << "No zeros found" << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (!isValidBinaryArray(arr, n)) {
        cout << "Invalid input" << endl;
        return 0;
    }

    countZero(arr, n);
    return 0;
}


/*
case 1:
Enter size of array: 5
Enter 5 elements : 1 1 1 0 0 
Number of zeros: 2

case 2:
Enter size of array: 5
Enter 5 elements : 0 0 1 1 1
Invalid input

*/