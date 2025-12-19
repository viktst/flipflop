#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("inputf.in"); string s;

    while(getline(fin, s)){
        map<char, vector<int>> positions;

        for (int i=0; i<s.size(); i++) {
            positions[s[i]].push_back(i);
        }
        
        int pos = 0;
        long total = 0;
        
        while(pos < s.size()){
            char c = s[pos];
            int other = (positions[c][0] == pos) ? positions[c][1] : positions[c][0];
            int steps = abs(pos - other);

            total += (isupper(c) ? -steps : steps);
            pos = other + 1;
        }
        cout << total << endl;
    }

    return 0;
}
