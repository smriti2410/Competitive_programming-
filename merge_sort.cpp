#include<bits/stdc++.h>
using namespace std;


//time complexity - O(nlogn), space O(n)

//function to merge two sorted sub-arrays into a single array

void merge(vector<int> &arr, int l,int mid,int r){
	int n1 = mid - l +1;
	int n2 = r - mid;

	//creating 2 temporary arrays 

	vector<int> L(n1),R(n2);

	//copying the elements from arr to these temp arrays 


    //left array starting from idx l from original array and ending at mid , size = mid -left +1
	for(int i=0;i<n1;i++){
		L[i]=arr[l+i];
	}

	//right array starting from idx mid+1 ending at r , size = r - mid +1 -1= r-mid

	for(int i=0;i<n2;i++){
		R[i]=arr[m+1+i];
	}


	int i,j,k;

	i=n1-1;
	j=n2-1;
	k=n1+n2-1;


	while(n1>=0 && n2>= 0){
		if(L[i]>R[j]){
			arr[k--]=L[i--];
		}

		else
		{
			arr[k--]=R[j--];
		}
	}

	// if L has elements remaining
	while(n1>=0){
		arr[k--]=L[i--];
	}


	//if R has elements remaining 
	while(n2>=0){
		arr[k--]=R[j--];
	}

}


void merge_sort(vector<int> &arr,int l,int r){
	//if there are more than 1 element then low<high 
	//calculation of mid must be like = l +(h-l)/2 and not (l+h)/2 because , l+h may  cause overflow for large values
	if(l<r){

		//divide the array into 2 halfs 
		int mid = l+(r-l)/2;

		//now sort the left and right side recursively 

		//left array is low to mid

		//right array is mid+1 to high

		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,r);

		//now merge two sorted halves into a single array

		merge(arr, l, mid, r);


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

	
	for(auto i : arr){
		cout<<i<<" ";
	}


}