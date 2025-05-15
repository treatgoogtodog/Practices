#include <iostream>
#include <cmath>

using namespace std;



class Vector{
    double x,y;
public:
    Vector(double _x, double _y) : x(_x) ,y(_y) {};
    Vector GetIterVct() const;
    double GetLength()const;
    
    friend Vct SumVct(const Vct* Vct1, const Vct* Vct2); // Hàm SumVct là friend được định nghĩa trong vector
};

using Vct = Vector; // Alias / Bí danh cho một class / typedef

double Vct::GetLength() const { // Các hàm trong lớp cần định nghĩa phạm vi lớp
    return sqrt(x*x + y*y);
}

Vct Vct::GetIterVct() const{
    double _x = this->x / this->GetLength();
    double _y = this->y / this->GetLength();
    Vct res = {_x,_y};
    return res;
}

Vct SumVct(const Vct* Vct1, const Vct* Vct2) {
    double _x = Vct1->x + Vct2->x; //Gây ra lỗi do Vector::x và Vector::y không thể truy cập ngoài class.
    double _y = Vct1->y + Vct2->y; //Bất khả thi nếu không có getter / định nghĩa friend
    return {_x,_y};
}
