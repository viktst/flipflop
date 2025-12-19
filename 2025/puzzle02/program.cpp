#include <bits/stdc++.h>
using namespace std;

long long fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    ifstream fin("inputf.in"); string s;

    long long current_height = 0, 
              max_height = 0;
    
    char prev = 0;
    int current_streak = 0;

    while(getline(fin, s)){
        for (int i=0; i<s.size(); i++) {
            if (prev && s[i] != prev) {
                if (prev == '^')
                    current_height += fibonacci(current_streak);
                else
                    current_height -= fibonacci(current_streak);
                max_height = max(max_height, current_height);
                current_streak = 0;
            }
            current_streak++;
            prev = s[i];
        }
    }
    if(current_streak > 0){
        if(prev == '^')
            current_height += fibonacci(current_streak);
        else
            current_height -= fibonacci(current_streak);
        max_height = max(max_height, current_height);
    }

    cout << max_height << endl;

    return 0;
}
