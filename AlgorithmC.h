#pragma once
#include "Base.h"

// Select Sort
int selectionSortC(int *arr, int n)
{
    int count;
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
    return count;
}

// Insertion Sort
int insertionSortC(int *arr, int n)
{
    int count;
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
    return count;
}

// Bubble Sort
int bubbleSortC(int *arr, int n)
{
    int count;
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
    return count;
}

// Shaker Sort
int shakerSortC(int *arr, int n)
{
    int count;
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
    return count;
}

// Shell Sort
int shellSortC(int *arr, int n)
{
    int count;
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
    return count;
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

int heapSortC(int *arr, int n)
{
    int count;
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
    return count;
}

// Merge Sort
int mergeSortC(int *arr, int n)
{
    int count;
    // Base case
    if (n <= 1)
        return;

    // Split the array into two halves
    int mid = n / 2;
    int *left = new int[mid];
    int *right = new int[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];

    // Sort the two halves
    mergeSortC(left, mid);
    mergeSortC(right, n - mid);

    // Merge the two halves
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy the remaining elements of left
    while (i < mid)
        arr[k++] = left[i++];

    // Copy the remaining elements of right
    while (j < n - mid)
        arr[k++] = right[j++];

    // Free the memory allocated to the two halves
    delete[] left;
    delete[] right;
    return count;
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

int quicksort(int arr[], int first, int last)
{
    int count;
    if (last - first + 1 < 10)
        insertionSortC(arr + first, last - first + 1);
    else
    {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(arr, first, last);
        // Sort subarrays S1 and S2
        quicksort(arr, first, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, last);
    }
    return count;
}

int quickSortC(int arr[], int n)
{
    return quicksort(arr, 0, n - 1);
}

// Counting sort
int countingSortC(int arr[], int n)
{
    int ccount;
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
    return ccount;
}

// Radix sort
int radixSortC(int arr[], int n)
{
    int rcount;
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
    return rcount;
}

// Flash Sort
int flashSortC(int arr[], int n)
{
    int fcount;
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
    return fcount;
}