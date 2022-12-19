#include <iostream>

// Function to sort an array using bubble sort
void bubbleSort(int arr[], int n)
{
    // Loop through the array
    for (int i = 0; i < 5; i++)
    {
        // Flag to check if the array is already sorted
        bool isSorted = true;

        // Loop through the array and swap adjacent elements if they are not in the correct order
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }

        // If the array is already sorted, we can stop the loop
        if (isSorted)
            break;
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
    int arr[] = {41, 7, 11, 22, 17, 3, 19, 5, 58, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform bubble sort on the array
    bubbleSort(arr, n);

    // Print the sorted array
    printArray(arr, n);

    return 0;
}
