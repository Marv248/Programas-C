#include<bits/stdc++.h>
using namespace std;

int main(){
    short n;
    int c, total=0, pay = 0;
    string s;
    vector<char> vitamins;

    cin >> n;
    while(n--0){
        cin >> c >> s;
        for (int i = 0; i < s.size(); i++)
        {
            // Check if the vitamin is already in the list
            // If not, add it to the list
            if(find(vitamins.begin(), vitamins.end(), s[i]) == vitamins.end()){
                vitamins.push_back(s[i]);
            }

            // If the vitamin is already in the list, we need to check if the cost is lower
            else{
                if(s.size() == 1){
                    // Find the other 2 vitamins in the list
                    char otherVitamin1, otherVitamin2;
                    // Find the other 2 vitamins in the list
                    for (int j = 0; j < vitamins.size(); j++)
                    {
                        if(vitamins[j] != s[i]){
                            if(otherVitamin1 == '\0'){
                                otherVitamin1 = vitamins[j];
                            } else {
                                otherVitamin2 = vitamins[j];
                                break;
                            }
                        }
                    }
                } else if(s.size() == 2){
                    // Finde the other vitamin in the list
                } else if(s.size() == 3){
                    total = c;
                }
            }
        }
    }

    system("pause");
    return 0;
}