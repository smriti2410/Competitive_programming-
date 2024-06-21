#include<bits/stdc++.h>
using namespace std;

// time complexity = O(n^2)
// space comlexity = O(1)

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n - i ; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
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


