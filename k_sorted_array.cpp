// we shall be given a k sorted array
// and we have to sort it in decreasing order
// we shall be given a parameter k
// k represents that every element in the given unsorted array is less than k distance(to the left or right) away 
// from it correct position in the sorted array

// eg 10 12 15 6 9
// k = 3
// sorted array 15 12 10 9 6

// so the above array is a k sorted array becasue every element is less than k distance away from its sorted position
// 10 : 2
// 12 : 0
// 15 : 2 
// 6 : 1 
// 9 : 1

// so every move is less than 3. Therfore it is a k sorted array

// eg 10 12 6 15 9
// k = 3
// sorted 15 12 10 9 6
// not a k sorted array as we need to move 15 3 locations to the left

// we can only move k-1 positions to the left or k-1 positions to the right

// so we saw that we can achieve sorting in best case of nlogn
// however we can improve on this if we are given a k sorted array
// eg 12 15 7 4 9
// k = 3

// for example for filling out the 0th position, we don't have to search for(max element) it in the whole array, we know that since it is a k sorted array
// it can only lie on indices 0,1 or 2
// so we shall only search over there
// for filling out index 1, the correct element can be at indices 0 or 1,2 or 3
// for filling out index 2, the correct element can be between indices 0 - 4
// so we shall implement it via priority queue

// first we shall push in the first 3 elements
// find out max and pop it out



#include<bits/stdc++.h>
using namespace std;

void kSortedArray(int input[], int n, int k)
{
	priority_queue<int> pq;

	for(int i = 0; i <k; i++)
	{
		pq.push(input[i]);
	}

	int j = 0; // tells us which vale we are currntly filling in the array

	for(i = k; i < n; i++)
	{
		input[j] = pq.top();
		pq.pop();
		pq.push(input[i]);
		j++;
	}

	while( !pq.empty())
	{
		input[j] = pq.top();
		pq.pop();
		j++;
	}
}
// complexity of the above is approximately nlogk, coz at all times the height of the tree does not exceed k
// and if k is small, we can approximate it to order of n

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int input[] = { 10,12,6,7, 9};
	int k = 3;
	kSortedArray(input, 5, k);

	for(int i = 0; i < n; i++)
	{
		cout<<input[i]<<" ";
	}

	cout<<"\n";

	return 0;
}