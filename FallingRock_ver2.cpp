#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

class Solution{
public:
    void FallingRock(vector<vector<char>>& map){
        pair<int, int> pos = WhereAmI(map); // {y,x}
        GenerateVisited(map);
        if(pos == make_pair(-1,-1)){cout << "Dead"; return;}
        if(CanFindEscape(map, pos)){
            cout << "YES";
        }else{
            cout << "NO";
        }
        
    }

private:

    vector<int> move = {-1,0,1};

    vector<vector<bool>>visited;

    void GenerateVisited(vector<vector<char>>& map){
        vector <bool> init(map[0].size(),false);
        for(int i = 0; i < map.size(); i++){
            visited.push_back(init);
        }
    }

    pair<int,int> WhereAmI(const vector<vector<char>>& map){
        for(int i = 0; i < map.size(); i ++){
            for(int j = 0; j < map.at(i).size(); j ++){
                if(map[i][j] == 'Y'){
                    return make_pair(i,j);
                }
            }
        }
        return make_pair(-1, -1);
    }

bool CanFindEscape(vector<vector<char>>& map, pair<int,int> pos){
   
    if(pos.second == 0){
        return true;
    }
    visited[pos.second][pos.first] = true;

    for(const int& col_offset : move){
        int next_row = pos.second - 1;
        int next_col = pos.first + col_offset;
        if(CheckValidPos(map, make_pair(next_row, next_col)) && !visited[next_row][next_col]){
            if(CanFindEscape(map, make_pair(next_row, next_col))){
                return true;
            }
        }
    }
    return false;
}

    bool CheckValidPos(const vector<vector<char>>& map, pair<int,int> pos){
        bool IsInside = pos.first >= 0 && pos.first < map.size() && pos.second >= 0 && pos.second < map[0].size();
        if(!IsInside){return IsInside;}
        return map[pos.first][pos.second] != 'R' &&((pos.second - 1 < 0)? true : map[pos.first-1][pos.second] != 'R');
    }
};

//=================================================================================================

void Test(vector<vector<char>>& MAP, string expect){
    Solution S;
    cout <<"GOT:"; S.FallingRock(MAP); cout<< " | EXPECTED: "<<expect<<endl;
    return;
}

struct TestCase {
    std::string name;
    std::vector<std::vector<char>> map;
    std::string expectedOutput;
};

int main(){
     std::vector<TestCase> testCases;

    // ... (Các test case tương tự như trong câu trả lời trước của tôi) ...
    // Ví dụ một vài test case:
    testCases.push_back({
        "1. Y can escape (straight up)",
        {
            {'R', 'E', 'R', 'E', 'R'},
            {'E', 'E', 'Y', 'E', 'E'},
            {'R', 'E', 'E', 'E', 'R'},
            {'E', 'E', 'E', 'E', 'E'},
            {'R', 'E', 'R', 'E', 'R'}
        },
        "YES"
    });

    testCases.push_back({
        "2. Y is completely blocked by R",
        {
            {'R', 'R', 'R', 'R', 'R'},
            {'E', 'E', 'R', 'E', 'E'},
            {'R', 'E', 'Y', 'E', 'R'},
            {'E', 'E', 'R', 'E', 'E'},
            {'R', 'R', 'R', 'R', 'R'}
        },
        "NO"
    });

    testCases.push_back({
        "3. Y starts on a rock",
        {
            {'E', 'E', 'E', 'E', 'E'},
            {'E', 'E', 'E', 'E', 'E'},
            {'R', 'R', 'Y', 'E', 'R'},
            {'E', 'E', 'E', 'E', 'E'},
            {'R', 'E', 'R', 'E', 'R'}
        },
        "YES"
    });

    testCases.push_back({
        "4.Bigger map",
        {
              {'R', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'R'},
              {'E', 'E', 'R', 'R', 'E', 'E', 'R', 'R', 'E', 'E'},
              {'E', 'E', 'R', 'E', 'E', 'E', 'E', 'R', 'E', 'E'},
              {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
              {'E', 'E', 'E', 'E', 'Y', 'E', 'E', 'E', 'E', 'E'}, // Vị trí người chơi 'Y'
              {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
              {'E', 'E', 'R', 'E', 'E', 'E', 'E', 'R', 'E', 'E'},
              {'R', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E', 'R'},
              {'R', 'R', 'E', 'E', 'E', 'E', 'E', 'E', 'R', 'R'}
        },
        "YES"
    });

    for(auto test : testCases){
        cout << test.name << endl;
        Test(test.map, test.expectedOutput);
    }
    return 0;
}