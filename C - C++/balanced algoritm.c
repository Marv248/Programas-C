#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int n, k;
    int count, min_count;
    int last_value, value;
    cin >> t;
    // For each test case
    for(int i=0; i<t; i++){
        // Read the number of elements and the maximum allowed difference
        cin >> n >> k;
        int a[n];
        // Read the array elements
        for(int j=0; j<n; j++){
            cin >> a[j];
        }
        // Set the minimum count to -1 initially
        min_count = -1;
        // Iterate through the array to find the minimum count of elements to remove
        for(int j=0; j<n; j++){
            if(n==1){
                min_count = 0;
                break;
            }
            // Initialize count to the total number of elements
            count = n;
            // Iterate through the array again to compare each element with the last_value
            for (int h = 0; h < n-1; h++){
                // If it's the first element, set last_value to the current element and decrement count
                if (j==h){
                    last_value = a[h];
                } 
                // For subsequent elements, check if the absolute difference with last_value is less than or equal to k
                else{
                    value = a[h];
                    // If the absolute difference is less than or equal to k, update last_value and decrement count
                    if(abs(last_value-value)<=k){
                        last_value = value;
                        --count;
                    }
                }
                // Update the minimum count if the current count is less than or equal to the previous minimum count
                if(count <= min_count || min_count == -1){
                    min_count = count;
                }
            }
        }
        // Output the minimum count of elements to remove for the current test case
        if(min_count != -1){
            cout << min_count << endl;
        }
    }
    system("pause");
    return 0;
}