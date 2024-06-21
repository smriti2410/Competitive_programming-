#include<bits/stdc++.h>
using namespace std;


//time complexity - O(nlogn), space O(n)

//function to merge two sorted sub-arrays into a single array
void merge(vector<int> &arr,int left, int mid, int right){
	int n1=mid-left+1;
	int n2= right - mid;

	//creating 2 sorted subarrays L and R

	vector<int> L(n1), R(n2);

	//copying data to the subarrays 

	for(int i=0;i<n1;i++){
		L[i]=arr[left+i];
	}

	for(int i=0;i<n2;i++){
		R[i]=arr[mid+1+i];
	}

	//merge temporary subarrays back to original array

	int i=0,j=0,k=left;

	while( i<n1 && j<n2 ){

		if(L[i]<=R[j]){
			arr[k++]=L[i++];
		}

		else{
			arr[k++]=R[j++];
		}

	}

	while(i<n1){
		arr[k++]=L[i++];
	}

	while(j<n2){
		arr[k++]=R[j++];
	}

}


void merge_sort(vector<int> &arr,int left,int right){
	if(left<right){
		int mid=left + (right-left)/2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);
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

	merge_sort(arr,0,n-1);

	for(auto i : arr){
		cout<<i<<" ";
	}


}