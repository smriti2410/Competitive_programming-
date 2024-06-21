#include<bits/stdc++.h>
using namespace std;


vector<int> merge(vector<int> &A,vector<int> &B, int m,int n){
	int i,j,k;
	i=j=k=0;
	vector<int> C(m+n);

	while(i<m && j<n){
		if(A[i]<B[j]){
			C[k++]=A[i++];
		}

		else{
			C[k++]=B[j++];
		}
	}

	while(i<m){
		C[k++]=A[i++];
	}
	while(j<n){
		C[k++]=B[j++];
	}

	return C;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int m,n;

	cin>> m>>n;

	vector<int> A(m),B(n);

	for (int i = 0; i < m; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }



	vector<int> C=merge(A,B,m,n);

	for(auto i:C)
	{
		cout<<i<<" ";
	}

}