#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct Complex
{
    double a,b;
};

using Cx = Complex;

void print(const Cx& C){
    stringstream to_print;
    
    to_print << setprecision(5) << defaultfloat;
    if(C.a != 0){
        to_print << C.a;
    }
    if(C.b != 0){
        if(abs(C.b) == 1){
            to_print << (C.a == 0)? (C.b == 1)? "i" : "-i" : (C.b == 1)? "+i" : "-i";
        }else{
            to_print << ((C.a == 0)? "" : (C.b > 0)? "+" : "" ) << C.b << "i";
        }
    }
    if (C.a == 0 && C.b == 0)
    {
        to_print << "0";
    }
    cout << to_print.str() << endl;
}

Cx add(const Cx& C1, const Cx& C2){
    Cx Cr = {C1.a + C2.a, C1.b + C2.b};
    return Cr;
}

int compare(const Cx& C1, const Cx& C2){
    double _C1_l = sqrt(C1.a * C1.a + C1.b*C1.b);
    double _C2_l = sqrt(C2.a * C2.a + C2.b*C2.b);
    return (_C1_l == _C2_l)? 0 : ((_C1_l > _C2_l)? 1 : -1 );
}

int main(){
    Complex c1 = {-1, 0};
Complex c2 = {1, -2};
Complex c3 = {0, 1};
Complex c4 = {0, 0};
Complex c5 = {2, 1};
print(c1);
print(c2);
print(c3);
print(c4);
print(c5);
cout << compare(c1, c2) << endl;
cout << compare(c3, c4) << endl;
cout << compare(c5, add(c5, c4)) << endl;
print(add(c1, add(c2, c3)));
}