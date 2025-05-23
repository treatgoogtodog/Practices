#include <iostream>

using namespace std;

class Solution {
public:
    int count = 0;
    void climb(int n, int &count) {
        if (n == 0) {
            count++;
            return;
        } else if (n < 0) {
            return;
        } else {
            for (int i = 1; i <= 2; i++) {
                climb(n - i, count);
            }
        }
    }

    int climbStairs(int n) {
        climb(n, count); 
        return count;
    }
};



int main(){
    int n = 5;
    Solution s;
    for(int i = 0; i < 10; i ++){
    cout << s.climbStairs(i) << endl;
    }
    return 0;
}