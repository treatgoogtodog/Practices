#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        vector<int> Tiling = {0,1,2,5};
        if(n < 5){
            return Tiling.at(n);
        }
        for(int i = 4; i <= n + 3; i++){
            Tiling.push_back(Tiling.at(i-1)*2 + Tiling.at(i-3));
        }
        return Tiling.at(n);
    }
};

int main(){
    int n;
    cin >> n;
    Solution sol;
    cout << sol.numTilings(n);
    return 0;
}