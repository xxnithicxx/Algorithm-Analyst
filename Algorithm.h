#pragma once
#include "Base.h"

// Select Sort
void SelectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// Insertion Sort
void InsertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Bubble Sort
void BubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Shaker Sort
void ShakerSort(int *arr, int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
        left++;
    }
}

// Shell Sort
void ShellSort(int *arr, int n)
{
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i - gap;
            while (j >= 0 && arr[j] > temp)
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
        gap /= 2;
    }
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

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        // Swap
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapsort(int *&arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        // Swap current element with the last element and start heapifying from the root
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Merge Sort
void merge(int arr[], int first, int mid, int last)
{
    // Initialize the local indices to indicate the subarrays
    int first1 = first, last1 = mid;    // The first subarray
    int first2 = mid + 1, last2 = last; // The second subarray
    // Copy the smaller element into the temp array
    int tempArr[first + last - 1]; // Temporary array
    int index = first1;            // Next available location in tempArr
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (arr[first1] <= arr[first2])
            tempArr[index++] = arr[first1++];
        else
            tempArr[index++] = arr[first2++];
    }
    while (first1 <= last1) // Finish the first subarray, if necessary
        tempArr[index++] = arr[first1++];
    while (first2 <= last2) // Finish the second subarray, if necessary
        tempArr[index++] = arr[first2++];
    // Copy the result back into the original array
    for (index = first; index <= last; ++index)
        arr[index] = tempArr[index];
}

void mergeSort(int arr[], int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;  // Index of midpoint
        mergeSort(arr, first, mid);    // Sort left half
        mergeSort(arr, mid + 1, last); // Sort right half
        merge(arr, first, mid, last);  // Merge the two halves
    }
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

int partition(int arr[], int first, int last)
{
    // Choose pivot using median-of-three selection
    int pivotIndex = sortFirstMiddleLast(arr, first, last);
    // Reposition pivot so it is last in the array
    swap(arr[pivotIndex], arr[last - 1]);
    pivotIndex = last - 1;
    int pivot = arr[pivotIndex];
    // Determine the regions S1 and S2
    int indexFromLeft = first + 1, indexFromRight = last - 2;
    int done = false;
    while (!done)
    {
        // Locate first entry on left that is >= pivot
        while (arr[indexFromLeft] < pivot)
            indexFromLeft++;
        // Locate first entry on right that is <= pivot
        while (arr[indexFromRight] > pivot)
            indexFromRight++;
        // Swap the two found entries
        if (indexFromLeft < indexFromRight)
        {
            swap(arr[indexFromLeft], arr[indexFromRight]);
            indexFromLeft++;
            indexFromRight++;
        }
        else
            done = true;
    }
    // Place pivot in proper position between S1 and S2
    swap(arr[pivotIndex], arr[indexFromLeft]);
    pivotIndex = indexFromLeft; // and mark its new location
    return pivotIndex;
}

void quickSort(int arr[], int first, int last)
{
    if (last - first + 1 < 10)
        InsertionSort(arr + first, last - first + 1);
    else
    {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(arr, first, last);
        // Sort subarrays S1 and S2
        quickSort(arr, first, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, last);
    }
}

// Counting sort
void countingSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    int *count = new int[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    int *output = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    delete[] count;
    delete[] output;
}

// Radix sort
void radixSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    int exp = 1;
    while (max / exp > 0)
    {
        int *count = new int[10];
        for (int i = 0; i < 10; i++)
            count[i] = 0;
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        int *output = new int[n];
        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++)
            arr[i] = output[i];
        delete[] count;
        delete[] output;
        exp *= 10;
    }
}

// Flash Sort
void flashSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    int exp = 1;
    while (max / exp > 0)
    {
        int *count = new int[10];
        for (int i = 0; i < 10; i++)
            count[i] = 0;
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        int *output = new int[n];
        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++)
            arr[i] = output[i];
        delete[] count;
        delete[] output;
        exp *= 10;
    }
}