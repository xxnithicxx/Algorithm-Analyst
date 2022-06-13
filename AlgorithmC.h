#pragma once
#include "Base.h"
#include "Algorithm.h"

// Selection Sort
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
long long heapifyC(int *arr, int n, int i)
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
        comp += heapifyC(arr, n, largest); // comp get from the heapify function
    }
    return comp;
}

long long heapSort(int *arr, int n)
{   
    long long comp = 0;
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0 && ++comp; i--)
    {    //comp of the for loop
        comp += heapifyC(arr, n, i); // comp get from the heapify function
    }

    for (int i = n - 1; i >= 0 && ++comp; i--)
    {   
        // Swap current element with the last element and start heapifying from the root
        swap(&arr[0], &arr[i]);
        comp += heapifyC(arr, i, 0);
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
long long flashSort(int a[], int n)
{
    long long comp = 0;
    int *__L = new int[n];
    if ((n <= 1) && ++comp)
        return comp;
    int m = n * 0.43;
    if ((m <= 2) && ++comp)
        m = 2;
    // int m = n;
    for (int i = 0; i < m && ++comp; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; i < n && ++comp; ++i)
    {
        if ((Mx < a[i]) && ++comp)
            Mx = a[i];
        if ((Mn > a[i]) && ++comp)
            Mn = a[i];
    }
    if ((Mx == Mn) && ++comp)
        return comp;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; i < n && ++comp; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; i < m && ++comp; ++i)
        __L[i] += __L[i - 1];
    // step 2
    int count = 0;
    int i = 0;
    while ((count < n) && ++comp)
    {
        int k = getK(a[i]);
        while ((i >= __L[k]) && ++comp)
            k = getK(a[++i]);
        int z = a[i];
        while ((i != __L[k]) && ++comp)
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    // step 3
    for (int k = 1; k < m && ++comp; ++k)
    {
        for (int i = __L[k] - 2; i >= __L[k - 1] && ++comp; --i)
            if ((a[i] > a[i + 1]) && ++comp)
            {
                int t = a[i], j = i;
                while ((t > a[j + 1]) && ++comp)
                {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
    }
    delete[] __L;
    return comp;
}