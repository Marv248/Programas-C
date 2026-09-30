#include<bits/stdc++.h>
using namespace std;

int main(){
    // Values for the number of elements and the number of queries
    // a,b are the range for which we want to calculate the sum
    int n,q, a,b;
    cin >> n >> q;

    // Create a vector to store the elements of the list, with an extra space for 1-based indexing (0th index is 0)
    vector<int> lista(n+1);
    
    // Read the elements of the list from input
    for(int i=1;i<=n;i++){
        cin >> lista[i];
    }

    // Create a prefix sum vector to store the cumulative sums of the elements
    vector<long long> p(n+1, 0);
 
    // P index 0 is initialized to 0, and we calculate the prefix sums for the rest of the elements
    p[0] = lista[0];
    for(int i = 1; i <= n; i++){
        p[i] = p[i-1] + lista[i];
    }

    // output the prefix sum array for debugging purposes
    while(q--){
        cin >> a >> b;
        long long sum = p[b] - p[a-1];
        cout << sum << endl;
    }

    return 0;
}