#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    void generateFromAlphabet(int n,int k){
        string res = "";
        generateTracker();
        Create(n,k,res);
        return;
    }

private:
    vector<bool> exist;

    void Create(int aa, int n, string& sts){
        if(sts.length() == n){cout << sts << endl; return;}
        for(int i = 0; i < aa; i ++){
            if(exist.at(i) == false){
                sts.push_back(char(int('a') + i));
                exist.at(i) = true;
                Create(aa,n, sts);
                sts.pop_back();
                exist.at(i) = false;
            }
        }
        return;
    }

    void generateTracker(){
        for(int i = 0; i < 26; i++){
            exist.push_back(false);
        }
    }
};

int main(){
    Solution S;
    S.generateFromAlphabet(3,3);
    return 0;
}