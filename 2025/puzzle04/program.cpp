#include <bits/stdc++.h>
using namespace std;

// part1:
long manhattan_distance(int x1, int x2, int y1, int y2){
    //        |x1 - x2| + |y1 - y2|
    return abs(x1 - x2) + abs(y1 - y2);
}

// part2:
long diagonal_distance(int x1, int x2, int y1, int y2){
    return max(abs(x1 - x2), abs(y1 - y2));
}

// part3:
long to_origin_distance(int x, int y){
    return manhattan_distance(0, x, 0, y);
}

int main() {
    ifstream fin("inputf.in"); string s;
    
    long total_steps = 0;
    int current_x = 0, current_y = 0;

    vector<pair<int,int>> trash;
    while(getline(fin, s)){
        int comma = s.find(',');
        int x = stoi(s.substr(0, comma));
        int y = stoi(s.substr(comma + 1)); 
        trash.push_back({x, y});
    }

    // sort the trash by distance
    sort(trash.begin(), trash.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        return to_origin_distance(a.first, a.second) < to_origin_distance(b.first, b.second);
    });

    // operate in sorted order
    for(int i=0; i<trash.size(); i++){
        int x = trash[i].first;
        int y = trash[i].second;

        total_steps += diagonal_distance(current_x, x, current_y, y);
        
        current_x = x; 
        current_y = y;
    }

    cout << total_steps << endl;

    return 0;
}
