/* k closest element
Given- array, x, k where x=element k= number of element we want which is closest to x in array
Eg.
Input arr={5,6,7,8,9}
Output- 8,6,7 (Output order may  vary)

We can do this with the help of Merge sort very easily but the time complexity will be o(nlogn)
So here we can use heap sort algorithm to reduce the time complexity. In this algo, time complexity will be o(nlogk)
*/

#include <iostream>
#include <queue>
#include <array>
using namespace std;

void maxHeap(array<int, 6> arr, int k, int x)
{
    priority_queue<pair<int, int>> max;
    for (int i = 0; i < arr.size(); i++)
    {
        max.push({abs(arr[i] - x), arr[i]});
        if (max.size() > k)
        {
            max.pop();
        }
    }
    while (max.size() > 0)
    {
        cout << max.top().second << " ";
        max.pop();
    }
}
int main()
{
    array<int, 6> arr = {5, 6, 7, 8, 9};
    maxHeap(arr, 3, 7);
    return 0;
}
