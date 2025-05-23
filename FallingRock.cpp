#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution{
public:
    void FallingRock(vector<vector<char>>& map){
        //Find current position
        pair<int, int> pos = WhereAmI(map);
        if(pos == make_pair(-1,-1)){cout << "Dead";}
        if(CanFindEscape(map, pos)){
            cout << "YES";
        }else{
            cout << "NO";
        }
        
    }

private:

    vector<int> move = {-1,0,1};

    pair<int,int> WhereAmI(const vector<vector<char>>& map){
        for(int i = 0; i < map.size(); i ++){
            for(int j = 0; j < map.at(i).size(); j ++){
                if(map[i][j] == 'Y'){
                    return make_pair(j,i);
                }
            }
        }
        return make_pair(-1, -1);
    }

    bool CanFindEscape(vector<vector<char>>& map, pair<int,int> pos){
        if(pos.second == 1){return true;}
        bool CanEscape = false;
        bool isNextAvail = false;
        for(const int& i : move){
            if(CheckValidPos(map, make_pair(pos.first + i, pos.second))){
                if(CanFindEscape(map, make_pair(pos.first + i, pos.second-1))){
                    return true;
                }
            }
        }
        return CanEscape;
    }

    bool CheckValidPos(vector<vector<char>>& map, pair<int,int> pos){
        bool IsInside = pos.first >= 0 && pos.first <= map[0].size() && pos.second >=0 && pos.second <= map.size();
        if(!IsInside){return IsInside;}
        return map[pos.first][pos.second] != 'R' && map[pos.first][pos.second + -1] != 'R';
    }
};


int main(){
    vector<vector<char>> banDo = {
    {'R', 'E', 'R', 'E', 'R'},
    {'E', 'E', 'E', 'E', 'E'},
    {'R', 'R', 'R', 'R', 'R'},
    {'E', 'E', 'E', 'E', 'E'},
    {'R', 'E', 'R', 'Y', 'R'}
};

    Solution S;
    S.FallingRock(banDo);
    return 0;
}