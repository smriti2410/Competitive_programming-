#include<bits/stdc++.h>
using namespace std;


// all odd numbers = last bit = 1
// all even numbers = last bit = 0

void check_odd_even(int n){

	// if n & 1 == 1 (last bit of n is 1 and hence it is odd) 
	if(n&1){
		cout<<"odd";

	}

	else{
		cout<<"even";
	}

}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n;
	cin>>n;


	check_odd_even(n);


}