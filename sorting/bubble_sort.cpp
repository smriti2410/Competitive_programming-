#include<bits/stdc++.h>
using namespace std;

// time complexity = O(n^2)
// space comlexity = O(1)
// pick up adj pairs of elements swap if a[i]>a[i+1], pushing the larger element at end 


void bubble_sort(vector<int> &arr){
	int n=arr.size();

	//outer loop , represents number of passes through the array , after each pass , largest elemnt is pushed at the end of the array , n-1 passes required for the array to be sorted 

	for(int i=0;i<n-1;i++){
		//inner loop is used to compare adjacent elemnts and swap if first element is larger than second 
		//with each pass , range of inner loop is decreased by one because largest element is sorted and moved to the end of the array
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
		}
		
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

	bubble_sort(arr);

	for(auto i : arr){
		cout<<i<<" ";
	}
	fclose(stdin);
	fclose(stdin);

	return 0;

}


