/*2. Implement a problem of move all zeroes to end of 
array. 
Statement: Given an array of random numbers, Push all the zero’s 
of a given array to the end of the array. For example, if the given 
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 
8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
same.  
Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0}; 
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0}; 

3. Implement a problem of smallest number with at 
least n trailing zeroes in factorial. 
Statement: Given a number n. The task is to find the 
smallest number whose factorial contains at least n 
trailing zeroes. 
Input : n = 1                  Output : 5  
Input : n = 6                  Output : 25
*/
#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int temp[100];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];

    for (int p = 0; p < k; p++)
        arr[left + p] = temp[p];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void moveZerosToEnd(int arr[], int n) {
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            arr[index++] = arr[i];
    }

    while (index < n)
        arr[index++] = 0;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int arr[] = {1, 3, 2, 0, 4, 0, 1};
    int n = 7;

    mergeSort(arr, 0, n - 1);
    moveZerosToEnd(arr, n);

    return 0;
}
/*output:: 
1 1 2 3 4 0 0 */