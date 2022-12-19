#include <iostream>
#include <algorithm>

// Function to sort an array using selection sort
void selectionSort(int arr[], int n)
{
    // Loop through the array
    for (int i = 0; i < n-1; i++)
    {
        // Find the minimum element in the unsorted part of the array
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // Swap the minimum element with the first element of the unsorted part of the array
        std::swap(arr[min_index], arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    // Array to be sorted
    int arr[] = {26, 24, 3, 17, 25, 24, 13, 60, 47, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform selection sort on the array
    selectionSort(arr, n);

    // Print the sorted array
    printArray(arr, n);

    return 0;
}
