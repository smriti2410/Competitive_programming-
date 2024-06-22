#include<bits/stdc++.h>
using namespace std;


// time complexity = O(n^2)
// space complexity = O(1)
// select the smallest elemnt of the unsorted part , swap it with first element of unsorted part , essentially dividing the array into 2 parts (sorted and unsorted)

void selection_sort(vector<int> &arr){
	int n = arr.size();

	//outer loop i marks the partitioning element between sorted and unsorted part of the array 
	// sorted part being idx 0 to i-1 , unsorted part being idx i to n-1 idx
	//i is therefore the first element of the unsorted part
	for(int i=0;i<n;i++){
		int minidx=i;

//inner for loop , used to determine the idx at which smallest element exists in  unsorted part 
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minidx])
				minidx=j;
		}

	swap(arr[i],arr[minidx]);

	}

}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

    int n;
	cin>>n;

	vector<int> arr(n);


	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	selection_sort(arr);

	for(auto i : arr){
		cout<<i<<" ";
	}
}