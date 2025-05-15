#include <iostream>

struct MyStruct{ // Trong struct, truy cập mặc định là public
    int x,y,z;
    char* name; 
    MyStruct(int x, int y, int z, char* name) : x(x), y(y), z(z), name(name){}

    void print() const {
        std::cout<< x << y << z;
    }

    MyStruct operator+(const MyStruct& other);

};//Lưu trên stack, có thể tự được giải phóng

class MyClass{  // Trong class, truy cập mặc định là private
    int x,y,z;
    char* name;
    MyClass(int x, int y, int z, char* name) : x(x), y(y), z(z), name(name){}

    MyClass operator+(const MyClass& other);

    friend  void MyFunc(MyClass Mc1);

};//Lưu trên heap, cần trình quản lý

//Cả struct và class đều có thể kế thừa

struct MyAqantStruct : MyStruct { // Kế thừa struct/ Mức độ truy cập đối với đối tương cha là Public
    int* ptr;
};

class MyAqantClass : MyClass { // Kế thừa class/  Mức độ truy cập đối với đối tương cha là Private

};

//Cú pháp kế thừa: struct/class <tên lớp con> : <Mức độ truy cập> <tên lớp cha> (phần còn lại)

/*
    Trong đó có 3 mức độ truy cập 
    Public : Giữ nguyên mức độ truy cập đối với lớp cha (Public -> Public, etc)
    Protected : Các thành phần có mức độ bảo mật thấp hơn Protected sẽ mang protected
    Private : Tất các các thành phần của lớp cha đều được bảo mật Private
*/

/* 
Struct / Class được kế thừa CÓ thể truy cập vào:
    Các dữ liệu public và protected của đối tượng cha
                            KHÔNG thể truy cập vào:abort
    Các dữ liệu private của đối tượng cha
*/

//Khi định nghĩa hàm thành viên của struct/class cần nạp class vào trước hàm

MyStruct MyStruct::operator+(const MyStruct& other){
    //Khi này hàm thành viên có thể truy cập vào thành phần private/protected của lớp.
}

void MyFunc(MyClass Mc1){
    Mc1.x = 9; //Hàm friend cũng có thể truy cập vào thành phần private
}

//Các kiểu trỏ

//Ta có 3 kiểu trỏ chính là this, other và con trỏ (Pointer)

//this là trỏ đến đối tượng hiện tại
//other trỏ đến đối tượng cùng kiểu trong tham chiếu
//Pointer (Chắc không cần nói tại làm game vắt lắm)

//override : Tính đa hình của đối tượng

class Animal {
public:
    virtual void speak() { std::cout << "Animal sound" << std::endl; } // Phương thức ảo có thể được ghi đè (Được khai báo bằng từ khoá virtual)
};
//!! Nếu không khai báo đây là phương thức ảo thì có chuyện gì xảy ra?
class Dog : public Animal {
public:
    void speak() override { std::cout << "Woof!" << std::endl; } //Phương thức được ghi đè
};

int main() {
    Animal* pet = new Dog();
    pet->speak();  // Gọi phiên bản của Dog nhờ tính đa hình
    delete pet;
    return 0;
}
