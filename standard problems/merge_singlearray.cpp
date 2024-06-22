#include<bits/stdc++.h>
using namespace std;
//merging 2 sorted arrays into single array without extra space 
//Time complexity is O(m+n) , no extra space hence O(1)
//note - when we are merging two sorted arrays into single array we should do backward merging to avoid overwriting of elemets in nums1
void mergeSingle(vector<int> &nums1,vector<int> &nums2,int m,int n){
	int i,j,k;
	i=m-1;
	j=n-1;
	k=m+n-1;


	while(i>=0 && j>=0){
		if(nums1[i]>nums2[j]){
			nums1[k--]=nums1[i--];

		}

		else{
			nums1[k--]=nums2[j--];
		}
	}

	while(i>=0){
		nums1[k--]=nums1[i--];
	}

	while(j>=0){
		nums1[k--]=nums2[j--];
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int m,n;

	cin>> m>>n;

	//nums1 vector must be initiallsed with size m+n , otherwise it will not accomodate all elements after merging and not give proper result 

	vector<int> nums1(m+n),nums2(n);

	//do not use for(auto i : A) for input as it creates a copy and not a refernce to the elements 

	for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    mergeSingle(nums1,nums2,m,n);

	for(int i=0;i<m+n;i++)
	{
		cout<<nums1[i]<<" ";
	}



}