class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0){return 0;}
        if(n == 0 || x == 1){return 1;}
        if(x == -1){return (n%2 == 0)? 1 : 1;}
        if(n > 0){return posiPow(x,n);}
        if(n < 0){return negaPow(x,n);}
        return 0;
    }

private:
    double negaPow(double x, int n){
        double pow = 1;
        for(int i = 0; i > n; i --){
            pow /= x;
        }
        return pow;
    }

    double posiPow(double x, int n){
        double pow = 1;
        for(int i = 0; i < n; i ++){
            pow *= x;
        }
        return pow;
    }
};

// -100.0 < x < 100.0
// -2^31 <= n <= 2^31-1 --> Tất cả các trường hợp vét giới hạn có thể xảy ra với x = 0; x = +-1
// n is an integer.
// Either x is not zero or n > 0.
// -10^4 <= x^n <= 10^4


//-2147483648 / 2.00 //shit description and testcase :)


#include <iostream>
using namespace std;

int main(){
    double x;
    cin >> x;
    int n;
    cin >> n;
    Solution MyPP;
    cout << MyPP.myPow(x,n);
    return 0;
}