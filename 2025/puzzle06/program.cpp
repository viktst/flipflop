#include <bits/stdc++.h>
using namespace std;

const int sky_size = 1000;
const int frame_size = 500;
const int center = 500;
const int total_pictures = 1000;
const long long second_per_year = 31556926;

int main() {
    ifstream fin("inputf.in"); string s;
    
    vector<pair<int, int>> birds;
    while(getline(fin, s)){
        int comma = s.find(',');
        int vx = stoi(s.substr(0, comma));
        int vy = stoi(s.substr(comma + 1));
        birds.push_back({vx, vy});
    }
    
    int min_x = center - frame_size / 2;
    int max_x = center + frame_size / 2 - 1;
    int min_y = center - frame_size / 2;
    int max_y = center + frame_size / 2 - 1;
    long long year_mod = second_per_year % sky_size;

    long long total_birds = 0;
    for(int i=0; i<total_pictures; i++){
        long long time_mod = ((i + 1) * year_mod) % sky_size;
        int birds_in_frame = 0;
        for(auto& b : birds){
            int vx = b.first; int vy = b.second;
            int x = ((vx * time_mod) % sky_size + sky_size) % sky_size;
            int y = ((vy * time_mod) % sky_size + sky_size) % sky_size;
            bool is_visible = (
                x >= min_x && 
                x <= max_x && 
                y >= min_y && 
                y <= max_y
            );
            if(is_visible)
                birds_in_frame += 1;
        }
        total_birds += birds_in_frame;
    }
    
    cout << total_birds;

    return 0;
}