#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int modulo = 10e8+7;
        for(int& i : nums){
            i = pow(i,t);
        }
        int len = 0;
        for(char i : s){
            len += nums.at(int(i)-int('a')) % modulo;
            len %= modulo;
        }
        return len;
    }
};

int main(){
    int t;
    string s;

    cin >> s >> t;

    vector <int> nums(26);

    for (int i = 0; i < 26; i++)
    {
        cin >>  nums[i];
    }
    
}