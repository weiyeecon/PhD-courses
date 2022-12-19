#include <iostream>

// Function to sort an array using insertion sort
void insertionSort(int arr[], int n)
{
    // Loop through the array
    for (int i = 1; i < n; i++)
    {
        // Get the element to be inserted
        int current = arr[i];

        // Shift all elements that are greater than the element to be inserted to the right
        int j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the element in the correct position
        arr[j + 1] = current;
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

    // Perform insertion sort on the array
    insertionSort(arr, n);

    // Print the sorted array
    printArray(arr, n);

    return 0;
}
