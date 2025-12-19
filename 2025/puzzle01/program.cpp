#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("inputf.in"); string s;

    int total_sum = 0;
    while(getline(fin, s)){
        int line_sum = 0;
        bool contains_banena = false;
        for(int i=0; i+1<s.size(); ++i){
            if(s[i] == 'b' && s[i+1] == 'a')
                line_sum += 1;
            if(s[i] == 'n' && s[i+1] == 'a')
                line_sum += 1;
            if(s[i] == 'n' && s[i+1] == 'e')
                contains_banena = true;
        }
        if(!contains_banena)
            total_sum += line_sum;
    }
    
    cout << total_sum;

    return 0;
}
