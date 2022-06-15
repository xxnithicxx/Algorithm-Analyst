#pragma once
#include "Base.h"
#include "Algorithm.h"

// Selection Sort
long long selectionSort(int *arr, int n)
{
    long long comp = 0;
    for (int i = 0; ++comp && i < n - 1 ; i++)
    {
        int min = i;
        for (int j = i + 1; ++comp && j < n ; j++)
        {
            if (++comp &&  arr[j] < arr[min]) {
                min = j;
            }
        }
        if (++comp && min != i )
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
    for (int i = 1; ++comp && i < n ; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while ((++comp && j >= 0 ) && (++comp && arr[j] > temp))
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
    for (int i = 0; ++comp && i < n - 1 ; i++)
    {   
        for (int j = 0; ++comp && (j < n - i - 1) ; j++)
        {   
            if (++comp && arr[j] > arr[j + 1])
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
    while (++comp && left < right)
    {
        for (int i = left; ++comp && i < right; i++)
        {   
            if (++comp && arr[i] > arr[i + 1])
            {   
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        right--;
        for (int i = right; ++comp && i > left; i--)
        {   
            if (++comp && arr[i] < arr[i - 1] )
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
    while (++comp && gap > 0)
    {
        for (int i = gap; ++comp && i < n; i++)
        {   
            int temp = arr[i];
            int j = i - gap;
            while ((++comp && j >= 0) && (++comp && arr[j] > temp))
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

    if ((++comp && l < n) && (++comp && arr[l] > arr[largest]))
        largest = l;

    if ((++comp && r < n) && (++comp && arr[r] > arr[largest]))
        largest = r;

    if (++comp && largest != i)
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
    for (int i = n / 2 - 1; ++comp && i >= 0; i--)
    {    //comp of the for loop
        comp += heapifyC(arr, n, i); // comp get from the heapify function
    }

    for (int i = n - 1; ++comp && i >= 0; i--)
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
    if (++comp && n <= 1)
        return comp;

    // Split the array into two halves
    int mid = n / 2;
    int *left = new int[mid];
    int *right = new int[n - mid];

    for (int i = 0; ++comp && i < mid; i++)
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
        if (++comp && left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy the remaining elements of left
    while (++comp && i < mid)
        arr[k++] = left[i++];

    // Copy the remaining elements of right
    while (++comp && j < n - mid)
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
    while (++comp && !done)
    {
        // Locate first entry on left that is >= pivot
        while (++comp && arr[indexFromLeft] < pivot ) {
            indexFromLeft++;
        }
        // Locate first entry on right that is <= pivot
        while (++comp && arr[indexFromRight] > pivot) {
            indexFromRight--;
        }
        // Swap the two found entries
        if (++comp && indexFromLeft <= indexFromRight )
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
    if (++subComp && last - first + 1 < 10)
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
    for (int i = 1; ++comp && i < n; i++)
        if (++comp && arr[i] > max)
            max = arr[i];
    int *count = new int[max + 1];
    for (int i = 0; ++comp && i <= max; i++)
        count[i] = 0;
    for (int i = 0; ++comp && i < n; i++)
        count[arr[i]]++;
    for (int i = 1; ++comp && i <= max; i++)
        count[i] += count[i - 1];
    int *output = new int[n];
    for (int i = n - 1; ++comp && i >= 0 ; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; ++comp && i < n; i++)
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
    for (int i = 1; ++comp && i < n; i++)
        if (++comp && arr[i] > max)
            max = arr[i];
    int exp = 1;
    while (++comp && max / exp > 0)
    {
        int *count = new int[10];
        for (int i = 0; ++comp && i < 10; i++)
            count[i] = 0;
        for (int i = 0; ++comp && i < n; i++)
            count[(arr[i] / exp) % 10]++;
        for (int i = 1; ++comp && i < 10; i++)
            count[i] += count[i - 1];
        int *output = new int[n];
        for (int i = n - 1; ++comp && i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        for (int i = 0; ++comp && i < n ; i++)
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
    if (++comp && (n <= 1))
        return comp;
    int m = n * 0.43;
    if (++comp && (m <= 2))
        m = 2;
    // int m = n;
    for (int i = 0; ++comp && i < m; ++i)
        __L[i] = 0;
    int Mx = a[0], Mn = a[0];
    for (int i = 1; ++comp && i < n; ++i)
    {
        if (++comp && (Mx < a[i]))
            Mx = a[i];
        if (++comp && (Mn > a[i]))
            Mn = a[i];
    }
    if (++comp && (Mx == Mn))
        return comp;
#define getK(x) 1ll * (m - 1) * (x - Mn) / (Mx - Mn)
    for (int i = 0; ++comp && i < n; ++i)
        ++__L[getK(a[i])];
    for (int i = 1; ++comp && i < m; ++i)
        __L[i] += __L[i - 1];
    // step 2
    int count = 0;
    int i = 0;
    while (++comp && (count < n))
    {
        int k = getK(a[i]);
        while (++comp && (i >= __L[k]))
            k = getK(a[++i]);
        int z = a[i];
        while (++comp && (i != __L[k]))
        {
            k = getK(z);
            int y = a[__L[k] - 1];
            a[--__L[k]] = z;
            z = y;
            ++count;
        }
    }
    // step 3
    for (int k = 1; ++comp && k < m; ++k)
    {
        for (int i = __L[k] - 2; ++comp && i >= __L[k - 1] ; --i)
            if (++comp && (a[i] > a[i + 1]))
            {
                int t = a[i], j = i;
                while (++comp && (t > a[j + 1]))
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