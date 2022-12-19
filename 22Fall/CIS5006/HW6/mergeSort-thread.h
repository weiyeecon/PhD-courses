#include<iostream>
#include<thread>
#include<algorithm>
#include<vector>

//The following may not the complete codes, I assume we have the merge funtion(the helper function) on the blackboard.
/*
reference:
https://cplusplus.com/reference/thread/thread/
*/
void merge_sort(int *arr, int left, int right, int min_chunk_size)
{
    if (left < right)
    {
        // Get the number of threads available.
        unsigned int maxthreads = std::thread::hardware_concurrency();

        // Compute the largest chunk size that will produce that many threads.
        int chunk_size = std::max(min_chunk_size, (right - left + 1) / maxthreads);

        // Split the array into chunks of size chunk_size and sort them in parallel.
        vector<std::thread> threads;
        for (int i = left; i < right; i += chunk_size)
        {
            int thread_left = i;
            int thread_right = std::min(i + chunk_size - 1, right);
            threads.push_back(std::thread(merge_sort, arr, thread_left, thread_right, min_chunk_size));
        }
        for (auto& t : threads)
        {
            t.join();//for each thread, if finish executing, pause. Like in the reference first.join(), second.join()
        }

        //merge as usual
        merge(arr, left, right, chunk_size);
    }
}
