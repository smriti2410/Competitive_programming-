// Divisible Subset
// Read problems statements in Mandarin Chinese and Russian.
// You are given a multiset of N integers. 
//Please find such a nonempty subset of it that the sum of the subset's elements is divisible by N. 
//Otherwise, state that this subset doesn't exist.

// Input
// The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
// The first line of each test consists of a single integer N - the size of the multiset.
// The second line of each test contains N single space separated integers - the multiset's elements.

// Output
// For each test case output:

// -1 if the required subset doesn't exist
// If the required subset exists, output two lines. Output the size of the subset on the first line and output the list of indices of the multiset's element that form the required subset. Of course, any number can be taken in the subset no more than once.
// If there are several such subsets, you can output any.
// Constraints
// 1 <= The sum of N over all the test cases <= 105
// Each element of the multiset is a positive integer, not exceeding 109.
// 1 <= N <= 15 : 37 points.
// 1 <= N <= 1000 : 24 points.
// 1 <= N <= 105 : 39 points.
// Example
// Input:
// 1
// 3
// 4 6 10
// Output:
// 1
// 2




//given - multiset (a set where elements can repeat themseleves)if N integers 

//to find - nonempty subset of this multiset so that sum of elements is divisible by N
// return -1 if no such subset exists 
// if such subset exists 
//first line = size of the subset 
//second line =list of indices of the multiset's element that form the required subset.


#include<bits/stdc++.h>
using namespace std;

void find_divisible_subset(vector<int> &arr,int n){

	unordered_map<int,int> prefix_mod;
	prefix_mod[0]=-1; //when prefix is itself divisible by n

	int prefix_sum=0;

//looping through array to calculate prefix sum
//Adding N ensures that if the result of prefix_sum % N was negative, it shifts it into the range [0, N).
// If the result was already positive, adding N simply shifts it into the range [N, 2N).

	for(int i=0;i<n;i++){

		prefix_sum+=arr[i];
		int mod =((prefix_sum%n)+n)%n;

	// condition when remiander found in map
	    if(prefix_mod.find(mod)!=prefix_mod.end()){
		int start = prefix_mod[mod]+1;
		int end = i;

		//printing the size of the subset

		cout<<end-start+1<<endl;


		//printing the indexes of elements of subset

		for(int j=start;j<=end;j++){
			cout<<j+1<<" "; // 1-based index therefore adding one
		}
		cout<<endl;
		return;
 		}

	//if the remainder entry not found in map , then add it along with the index till which prefix sum when divided by n gives remiander mod

	else {
		prefix_mod[mod]=i;
	}
}
}



//The prefix sum is a concept in mathematics and computer science where we compute the cumulative sum of elements in an array up to a certain index.

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	// number of test cases
	int t;
	cin>>t;


	while(t--){

		int n;
		cin>>n;
		vector<int> arr(n);

		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		find_divisible_subset(arr,n);

	}

}