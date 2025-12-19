#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("inputf.in"); string s;

    map<string, int> counts;
    
    while(getline(fin, s)){
        counts[s] += 1;
    }

    string most_common = "";
    int max = 0;

    for(auto& pair : counts){
        if(pair.second > max){
            max = pair.second;
            most_common = pair.first;
        }
    }

    cout << most_common << endl;

    return 0;
}
