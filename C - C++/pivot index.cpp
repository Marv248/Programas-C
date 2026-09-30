#include<bits/stdc++.h>
using namespace std;

int main (){
    vector<int> nums = {2,1,-1};
    int n=nums.size();
    int total = 0;

    // Foreach
    for(int x : nums){
        total += x;
    }

    int left = 0;
    int indx = -1;
    for (int i = 0; i < n; i++)
    {
        if ( left == total - left - nums[i]){
            indx = i;
            break;
        }
    }
    /*
    vector <int> pivot (nums.size()+1, 0);
    int idx=0;


    for (int i= 1; i<nums.size(); i++){
        pivot[i] = pivot[i-1] + nums[nums.size()];
    }

    for(int i = 1; i<nums.size(); i++){
        if(pivot[i-1] == pivot[i] + nums[nums.size()]){
            idx = i;
            break;
        }
    } */

    cout << indx << endl;
    system("pause");
    return 0;
}