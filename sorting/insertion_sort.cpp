#include<bits/stdc++.h>
using namespace std;

// time complexity = O(n^2)
// space complexity = O(1)

void insertion_sort(vector<int> &arr){
	int n=arr.size();
	//start the outer loop with 2nd element 
	//outer loop selects each element one by one and places it at correct position rletaive to already sorted part , here we assume first element  to be sorted 
	for(int i=1;i<n;i++){
		//key stores value of current element that needs to be placed in sorted portion of the array, 
		//key element will comapred to rest of the elements to find its correct position 
		int key = arr[i];
		int j=i-1;
		//the inner loop is used to shift elements of sorted portion to the right to make space for key element.
		//the loop keeps shifting elements to right as lonbg as current element is greater than key and j is non negative 
		//at the end of the inner loop we will find the correct position for key to be inserted 

		while( j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}

		//inserting the key in correct position in sorted portion of array 

		arr[j+1]=key;
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

	insertion_sort(arr);

	for(auto i : arr){
		cout<<i<<" ";
	}

}