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

void find_divisible_subset(vector<int>& a,int n) {
    bool found = false;

    // Check if any single element is divisible by n
    for (int i = 1; i <= n; ++i) {
        if (a[i] % n == 0 && !found) {
            cout << "1\n" << i << "\n";
            found = true;
            return;
        }
    }

    // If no single element is divisible, find a subset using prefix sums
    vector<int> f(n + 1, 0);
    unordered_map<int, int> was;
    was[0] = 0;

    int i;
    for (i = 1; i <= n; ++i) {
        f[i] = (f[i - 1] + a[i]) % n;
        if (f[i] < 0) f[i] += n; // Handle negative remainders
        if (was.find(f[i]) != was.end()) break;
        was[f[i]] = i;
    }

    int j = was[f[i]];
    cout << i - j << "\n";
    for (++j; j <= i; ++j) {
        cout << j;
        if (j != i) cout << " ";
    }
    cout << "\n";
}

int main() {

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int tn;
    cin >> tn;
    int sum = 0;

    for (int ti = 0; ti < tn; ++ti) {
        int n;
        cin >> n;
        sum += n;
        vector<int> a(n + 1);

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        find_divisible_subset(a,n);
    }

  
    return 0;
}

//The prefix sum is a concept in mathematics and computer science where we compute the cumulative sum of elements in an array up to a certain index.

	


