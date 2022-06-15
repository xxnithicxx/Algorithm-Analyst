#pragma once
#include "Base.h"

// Selection Sort
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
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// Insertion Sort
void InsertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
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
    int left = 0, right = n - 1;
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
            int j = i;
            while (j >= gap && arr[j] < arr[j - gap])
            {
                int temp = arr[j];
                arr[j] = arr[j - gap];
                arr[j - gap] = temp;
                j -= gap;
            }
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

void HeapSort(int *arr, int n)
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
void MergeSort(int *arr, int n)
{
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
    MergeSort(left, mid);
    MergeSort(right, n - mid);

    // Merge the two halves
    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left
    while (i < mid)
    {
        arr[k++] = left[i++];
    }

    while (j < n - mid)
    {
        arr[k++] = right[j++];
    }

    delete[] left;
    delete[] right;
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
            indexFromRight--;
        // Swap the two found entries
        if (indexFromLeft < indexFromRight)
        {
            swap(arr[indexFromLeft], arr[indexFromRight]);
            indexFromLeft++;
            indexFromRight--;
        }
        else
            done = true;
    }
    // Place pivot in the right location
    swap(arr[indexFromLeft], arr[pivotIndex]);
    pivotIndex = indexFromLeft; // New pivot index
    return pivotIndex;
}

void Quicksort(int arr[], int first, int last)
{
    if (last - first + 1 < 10)
        InsertionSort(arr + first, last - first + 1);
    else
    {
        // Create the partition: S1 | Pivot | S2
        int pivotIndex = partition(arr, first, last);
        // Sort the two sub-arrays

        Quicksort(arr, first, pivotIndex - 1);
        Quicksort(arr, pivotIndex + 1, last);
    }
    return;
}

void QuickSort(int *arr, int n)
{
    Quicksort(arr, 0, n - 1);
}

// Counting Sort
void CountingSort(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
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
    return;
}

// Radix Sort
void RadixSort(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
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
    return;
}

/**
 * Flash Sort
 * Average complexity: O(n + m)
 * Best Case: O(n + m)
 * Worst Case: O(n^2)
 * Space: O(m)
 * Note: m = 0.43n
 * Not Stable
 * @reference  https://github.com/leduythuccs/Sorting-Algorithms/blob/master/sorting-methods/flash_sort.h
 *             https://pages.cs.wisc.edu/~deppeler/cs400/readings/Sorting/Dr.%20Dobb's%20Journal%20February%201998_%20The%20Flashsort1%20Algorithm.pdf
 */
void FlashSort(int a[], int n)
{
    int *__L = new int[n];
    if (n <= 1)
        return;
    int m = n * 0.43;
    if (m <= 2)
        m = 2;
    // int m = n;
    for (int i = 0; i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (Mx < a[i])
            Mx = a[i];
        if (Mn > a[i])
            Mn = a[i];
    }
    if (Mx == Mn)
        return;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; i < m; ++i)
        __L[i] += __L[i - 1];
    // step 2
    int count = 0;
    int i = 0;
    while (count < n)
    {
        int k = getK(a[i]);
        while (i >= __L[k])
            k = getK(a[++i]);
        int z = a[i];
        while (i != __L[k])
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    // step 3
    for (int k = 1; k < m; ++k)
    {
        for (int i = __L[k] - 2; i >= __L[k - 1]; --i)
            if (a[i] > a[i + 1])
            {
                int t = a[i], j = i;
                while (t > a[j + 1])
                {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
    }
    delete[] __L;
}