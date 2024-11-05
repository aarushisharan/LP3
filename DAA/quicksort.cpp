#include <iostream>
#include <vector>
#include<cstdlib>//for rand()
#include<ctime>// for srand()
using namespace std;

//--------QUICK SORT-------
int partition(vector<int> &arr, int low, int high, int &swapsDet) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while (i < j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
            swapsDet++;
        }
    }
    swap(arr[j], arr[low]);
    swapsDet++;
    return j;
}

void quickSort(vector<int> &arr, int low, int high, int &compDet, int &swapsDet) {
    if (low < high) {
        int pIndex = partition(arr, low, high, swapsDet);
        compDet += (high - low); // Count comparisons
        quickSort(arr, low, pIndex - 1, compDet, swapsDet);
        quickSort(arr, pIndex + 1, high, compDet, swapsDet);
    }
}

//----RANDOMIZED QUICK SORT
int partitionRand(vector<int>&arr, int low, int high, int &swapsRand)
{
    int pivotIndex= low+rand()%(high-low+1);
    swap(arr[low],arr[pivotIndex]);
    swapsRand++;
    
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while (i < j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
            swapsRand++;
        }
    }
    swap(arr[j], arr[low]);
    swapsRand++;
    return j;
}

void quickSortRand(vector<int> &arr, int low, int high, int &compRand, int &swapsRand) 
{
    if (low < high) 
    {
        int pIndex = partition(arr, low, high, swapsRand);
        compRand += (high - low); // Count comparisons
        quickSort(arr, low, pIndex - 1, compRand, swapsRand);
        quickSort(arr, pIndex + 1, high, compRand, swapsRand);
    }
}

// Function to print the array
void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter elements: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    vector<int>arr2=arr1;
    cout << "Original array for deterministic quick sort:\n";
    printArray(arr1);

    int compDet = 0;
    int swapsDet = 0;
    
    quickSort(arr1, 0, n - 1, compDet, swapsDet);

    cout << "Sorted array (Deterministic):\n";
    printArray(arr1);
    cout << "Deterministic Quick Sort Comparisons: " << compDet << endl;
    cout << "Deterministic Quick Sort Swaps: " << swapsDet << endl;
    
     cout << "Original array for randomized quick sort:\n";
    printArray(arr2);

    int compRand = 0;
    int swapsRand = 0;
    
    quickSort(arr2, 0, n - 1, compRand, swapsRand);

    cout << "Sorted array (Randomized):\n";
    printArray(arr2);
    cout << "Randomized Quick Sort Comparisons: " << compRand << endl;
    cout << "Randomized Quick Sort Swaps: " << swapsRand<< endl;

    return 0;
}
