#pragma once
#include "Base.h"

// Select Sort
long long selectionSort(int *arr, int n)
{
    long long comp = 0;
    for (int i = 0; i < n - 1 && ++comp; i++)
    {
        int min = i;
        for (int j = i + 1; j < n && ++comp; j++)
        {
            if (arr[j] < arr[min] && ++comp) {
                min = j;
            }
        }
        if (min != i && ++comp)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    return comp;
}

// Insertion Sort
long long insertionSort(int *arr, int n)
{
    long long comp = 0;
    for (int i = 1; i < n && ++comp; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while ((j >= 0 && ++comp ) && (arr[j] > temp && ++comp))
        {   
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    return comp;
}

// Bubble Sort
long long bubbleSort(int *arr, int n)
{
    long long comp = 0;
    for (int i = 0; i < n - 1 && ++comp; i++)
    {   
        for (int j = 0; (j < n - i - 1) && ++comp; j++)
        {   
            if (arr[j] > arr[j + 1] && ++comp)
            {   
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comp;
}

// Shaker Sort
long long shakerSort(int *arr, int n)
{   
    long long comp = 0;
    int left = 0;
    int right = n - 1;
    while (left < right && ++comp)
    {
        for (int i = left; i < right && ++comp; i++)
        {   
            if (arr[i] > arr[i + 1] && ++comp)
            {   
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left && ++comp; i--)
        {   
            if (arr[i] < arr[i - 1] && ++comp)
            {   
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        left++;
    }
    return comp;
}

// Shell Sort
long long shellSort(int *arr, int n)
{   
    long long comp = 0;
    int gap = n / 2;
    while (gap > 0 && ++comp)
    {
        for (int i = gap; i < n && ++comp; i++)
        {   
            int temp = arr[i];
            int j = i - gap;
            while ((j >= 0 && ++comp) && (arr[j] > temp && ++comp))
            {   
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
        gap /= 2;
    }
    return comp;
}

// Heap Sort
int leftChild(int i)
{
    return i << 1;
}

int rightChild(int i)
{
    return (-(~(i << 1)));
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

long long heapify(int *arr, int n, int i)
{
    long long comp = 0;
    int largest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if ((l < n && ++comp) && (arr[l] > arr[largest] && ++comp))
        largest = l;

    if ((r < n && ++comp) && (arr[r] > arr[largest] && ++comp))
        largest = r;

    if (largest != i && ++comp)
    {
        // Swap
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        comp += heapify(arr, n, largest); // comp get from the heapify function
    }
    return comp;
}

long long heapSort(int *arr, int n)
{   
    long long comp = 0;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0 && ++comp; i--)
    {    //comp of the for loop
        comp += heapify(arr, n, i); // comp get from the heapify function
    }

    for (int i = n - 1; i >= 0 && ++comp; i--)
    {   
        // Swap current element with the last element and start heapifying from the root
        swap(&arr[0], &arr[i]);
        comp += heapify(arr, i, 0);
    }
    return comp;
}

// Merge Sort
long long mergeSort(int *arr, int n)
{   
    long long comp = 0;
    // Base case
    if (n <= 1 && ++comp)
        return comp;

    // Split the array into two halves
    int mid = n / 2;
    int *left = new int[mid];
    int *right = new int[n - mid];

    for (int i = 0; i < mid && ++comp; i++)
        left[i] = arr[i];
    for (int i = mid; i < n && ++comp; i++)
        right[i - mid] = arr[i];

    // Sort the two halves
    comp += mergeSort(left, mid);
    comp += mergeSort(right, n - mid);

    // Merge the two halves
    int i = 0, j = 0, k = 0;
    while ((i < mid && ++comp) && (j < n - mid && ++comp))
    {
        if (left[i] <= right[j] && ++comp)
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy the remaining elements of left
    while (i < mid && ++comp)
        arr[k++] = left[i++];

    // Copy the remaining elements of right
    while (j < n - mid && ++comp)
        arr[k++] = right[j++];

    // Free the memory allocated to the two halves
    delete[] left;
    delete[] right;
    return comp;
}

// Quick Sort
int sortFirstMiddleLast(int arr[], int first, int last)
{
    int mid = first + (last - first) / 2;
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    if (arr[mid] > arr[last])
        swap(arr[mid], arr[last]);
    if (arr[first] > arr[mid])
        swap(arr[first], arr[mid]);
    return mid;
}

int partition(int arr[], int first, int last, long long& comp)
{
    // Choose pivot using median-of-three selection
    int pivotIndex = sortFirstMiddleLast(arr, first, last);
    comp += 3;
    // Reposition pivot so it is last in the array
    swap(arr[pivotIndex], arr[last - 1]);
    pivotIndex = last - 1;
    int pivot = arr[pivotIndex];
    // Determine the regions S1 and S2
    int indexFromLeft = first + 1, indexFromRight = last - 2;
    int done = false;
    while (!done && ++comp)
    {
        // Locate first entry on left that is >= pivot
        while (arr[indexFromLeft] < pivot && ++comp) {
            indexFromLeft++;
        }
        // Locate first entry on right that is <= pivot
        while (arr[indexFromRight] > pivot && ++comp) {
            indexFromRight--;
        }
        // Swap the two found entries
        if (indexFromLeft <= indexFromRight && ++comp)
        {
            swap(arr[indexFromLeft], arr[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        }
        else
            done = true;
    }
    // Place pivot in proper position between S1 and S2
    swap(arr[pivotIndex], arr[indexFromLeft]);
    pivotIndex = indexFromLeft; // and mark its new location
    return pivotIndex;
}

long long quicksort(int arr[], int first, int last)
{
    long long subComp = 0;
    if (last - first + 1 < 10)
        insertionSort(arr + first, last - first + 1);
    else
    {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(arr, first, last, subComp);
        // Sort subarrays S1 and S2
       
        subComp += quicksort(arr, first, pivotIndex - 1);
        subComp += quicksort(arr, pivotIndex + 1, last);
    }
    return subComp;
}

long long quickSort(int arr[], int n)
{
    long long comp;
    comp = quicksort(arr, 0, n - 1);
    return comp;
}

// Counting sort
long long countingSort(int arr[], int n)
{   
    long long comp = 0;
    int max = arr[0];
    for (int i = 1; i < n && ++comp; i++)
        if (arr[i] > max && ++comp)
            max = arr[i];
    int *count = new int[max + 1];
    for (int i = 0; i <= max && ++comp; i++)
        count[i] = 0;
    for (int i = 0; i < n && ++comp; i++)
        count[arr[i]]++;
    for (int i = 1; i <= max && ++comp; i++)
        count[i] += count[i - 1];
    int *output = new int[n];
    for (int i = n - 1; i >= 0 && ++comp; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n && ++comp; i++)
        arr[i] = output[i];
    delete[] count;
    delete[] output;
    return comp;
}

// Radix sort
long long radixSort(int arr[], int n)
{
    long long comp = 0;
    int max = arr[0];
    for (int i = 1; i < n && ++comp; i++)
        if (arr[i] > max && ++comp)
            max = arr[i];
    int exp = 1;
    while (max / exp > 0 && ++comp)
    {
        int *count = new int[10];
        for (int i = 0; i < 10 && ++comp; i++)
            count[i] = 0;
        for (int i = 0; i < n && ++comp; i++)
            count[(arr[i] / exp) % 10]++;
        for (int i = 1; i < 10 && ++comp; i++)
            count[i] += count[i - 1];
        int *output = new int[n];
        for (int i = n - 1; i >= 0 && ++comp; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n && ++comp; i++)
            arr[i] = output[i];
        delete[] count;
        delete[] output;
        exp *= 10;
    }
    return comp;
}

// Flash Sort
long long flashSort(int arr[], int n)
{   
    long long comp = 0;
    int max = arr[0];
    for (int i = 1; i < n && ++comp; i++)
        if (arr[i] > max && ++comp)
            max = arr[i];
    int exp = 1;
    while (max / exp > 0 && ++comp)
    {
        int *count = new int[10];
        for (int i = 0; i < 10 && ++comp; i++)
            count[i] = 0;
        for (int i = 0; i < n && ++comp; i++)
            count[(arr[i] / exp) % 10]++;
        for (int i = 1; i < 10 && ++comp; i++)
            count[i] += count[i - 1];
        int *output = new int[n];
        for (int i = n - 1; i >= 0 && ++comp; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n && ++comp; i++)
            arr[i] = output[i];
        delete[] count;
        delete[] output;
        exp *= 10;
    }
    return comp;
}