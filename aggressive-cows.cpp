/*
You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
You are also given an integer ‘k’ which denotes the number of aggressive cows.
You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any
two of them is the maximum possible. Find the maximum possible minimum distance.

Example:
Input:
    n=5
    k=3
    stalls : {1,2,4,8,9}
Output: 3

Explanation: The first cow can be placed at stalls[0], the second cow can be placed at stalls[2],
             the third cow can be placed at stalls[3]. The minimum distance between the cows,
             in this case, is 3, which also is largest among all possible ways.

Input:
    n=5
    k=3
stalls = { 10,1,2,7,5}
Output: 4

Explanation: The first cow can be placed at stalls[0], the second cow can be placed at stalls[1],
             the third cow can be placed at stalls[4]. The minimum distance between the cows,
             in this case, is 4, which also is largest among all possible ways.

*/

#include <iostream>
#include <algorithm>

bool isPossible(int arr[], int size, int k, int minDist)
{
    int cowsCount = 1, lastStall = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] - lastStall >= minDist)
        {
            cowsCount++;
            lastStall = arr[i];
        }
        if (cowsCount == k)
            return true;
    }
    return false;
}

// Time-Complexity: O(maxi-mini)*O(size) , Space-Complexity: O(1)
int SolutionByLinearSearch(int arr[], int size, int k)
{
    for (int i = 1; i < arr[size - 1] - arr[0]; i++)
    {
        if (isPossible(arr, size, k, i))
            continue;
        else
        {
           return (i-1) ;
        }
    }
    return -1 ;
}

//Time-Complexity: O(size*log size) , Space-Complexity: O(1)
int SolutionByBinarySearch(int arr[], int size, int k)
{
    int start = 1, end = arr[size - 1] - arr[0], mid = start + ((end - start) / 2), ans = -1;

    while (start <= end)
    {
        if (isPossible(arr, size, k, mid))
        {
            ans = mid ; 
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
    return (ans) ; 
}

int main()
{
    int arr[] = {10, 1, 2, 7, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    std ::sort(arr, arr + size);

    std  :: cout << "Maximized Minimum Value is: " << SolutionByLinearSearch(arr, size, k) << "\n";
    std  :: cout << "Maximized Minimum Value is: " << SolutionByBinarySearch(arr, size, k);
}