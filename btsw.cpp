#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

// Hàm để biểu diễn băng của máy Turing
// Băng được biểu diễn bằng một vector các ký tự, với các ký tự 'B' biểu thị ô trống.
typedef vector<char> Tape;

// Hàm để in băng
void printTape(const Tape& tape, int headPosition) {
    for (int i = 0; i < tape.size(); ++i) {
        if (i == headPosition) {
            cout << "[" << tape[i] << "]"; // In ký tự hiện tại trong ngoặc vuông
        } else {
            cout << tape[i];
        }
    }
    cout << endl;
}

// Hàm để khởi tạo băng với dữ liệu đầu vào
// Dữ liệu đầu vào là một xâu ký tự, ví dụ "111*11" để biểu diễn hai số 3 và 2.
Tape initializeTape(const string& input) {
    Tape tape(200, 'B'); // Khởi tạo băng với 200 ô, tất cả là 'B'
    int startPosition = 100; // Đặt đầu đọc ở giữa băng
    for (int i = 0; i < input.length(); ++i) {
        tape[startPosition + i] = input[i];
    }
    return tape;
}

// Hàm thực thi máy Turing cho bài toán 1: f(n) = n + 3
void turing1(Tape& tape, int& headPosition) {
    // Di chuyển đầu đọc đến cuối xâu đầu vào
    while (tape[headPosition] != 'B') {
        headPosition++;
    }
    // Viết thêm ba số 1
    tape[headPosition++] = '1';
    tape[headPosition++] = '1';
    tape[headPosition] = '1';
}

// Hàm thực thi máy Turing cho bài toán 2: f(n) = n % 3
void turing2(Tape& tape, int& headPosition) {
    int count = 0;
    while (tape[headPosition] != 'B') {
        if (tape[headPosition] == '1') {
            count++;
        }
        headPosition++;
    }
    count %= 3;
    // Xóa xâu đầu vào
    headPosition = 100;
    while (tape[headPosition] != 'B') {
        tape[headPosition++] = 'B';
    }
    headPosition = 100;
    // Ghi kết quả
    if (count == 0) tape[headPosition] = '0';
    else if (count == 1) tape[headPosition] = '1';
    else tape[headPosition] = '1';
}

// Hàm thực thi máy Turing cho bài toán 2a: f(n) = n % 2
void turing2a(Tape& tape, int& headPosition) {
    int count = 0;
    while (tape[headPosition] != 'B') {
        if (tape[headPosition] == '1') {
            count++;
        }
        headPosition++;
    }
    count %= 2;
     // Xóa xâu đầu vào
    headPosition = 100;
    while (tape[headPosition] != 'B') {
        tape[headPosition++] = 'B';
    }
    headPosition = 100;
    // Ghi kết quả
    if (count == 0) tape[headPosition] = '0';
    else tape[headPosition] = '1';
}

// Hàm thực thi máy Turing cho bài toán 2b: f(n) = n % 5
void turing2b(Tape& tape, int& headPosition) {
    int count = 0;
    while (tape[headPosition] != 'B') {
        if (tape[headPosition] == '1') {
            count++;
        }
        headPosition++;
    }
    count %= 5;
     // Xóa xâu đầu vào
    headPosition = 100;
    while (tape[headPosition] != 'B') {
        tape[headPosition++] = 'B';
    }
    headPosition = 100;
    // Ghi kết quả
    if (count == 0) tape[headPosition] = '0';
    else if (count == 1) tape[headPosition] = '1';
    else if (count == 2) tape[headPosition] = '1';
    else if (count == 3) tape[headPosition] = '1';
    else tape[headPosition] = '1';
}

// Hàm thực thi máy Turing cho bài toán 3: f(n) = 2n
void turing3(Tape& tape, int& headPosition) {
    int originalEnd = 0;
    while (tape[headPosition] != 'B')
    {
        headPosition++;
    }
    originalEnd = headPosition;
    headPosition = 100;
    // Di chuyển đầu đọc đến cuối xâu đầu vào
    while (tape[headPosition] != 'B') {
        if (tape[headPosition] == '1')
        {
            tape[originalEnd++] = '1';
            tape[originalEnd++] = '1';
        }
        headPosition++;
    }
}

// Hàm thực thi máy Turing cho bài toán 3b: f(n) = 3n
void turing3b(Tape& tape, int& headPosition) {
    int originalEnd = 0;
    while (tape[headPosition] != 'B')
    {
        headPosition++;
    }
    originalEnd = headPosition;
    headPosition = 100;
    // Di chuyển đầu đọc đến cuối xâu đầu vào
    while (tape[headPosition] != 'B') {
        if (tape[headPosition] == '1')
        {
            tape[originalEnd++] = '1';
            tape[originalEnd++] = '1';
            tape[originalEnd++] = '1';
        }
        headPosition++;
    }
}

// Hàm thực thi máy Turing cho bài toán 4: f(n1, n2) = min(n1, n2)
void turing4(Tape& tape, int& headPosition) {
    int firstEnd = 0;
    int secondStart = 0;
     while (tape[headPosition] != '*')
    {
        headPosition++;
    }
    secondStart = headPosition;
    headPosition = 100;
    while (tape[headPosition] != '*')
    {
        firstEnd++;
        headPosition++;
    }
    int secondEnd = firstEnd + 1;
    while(tape[secondEnd] != 'B')
    {
        secondEnd++;
    }
    headPosition = 100;
    while (headPosition < firstEnd && secondStart + 1 < secondEnd)
    {
        tape[headPosition] = 'B';
        tape[secondStart + 1] = 'B';
        headPosition++;
        secondStart++;
    }
    if (headPosition == firstEnd)
    {
        for (int i = secondStart + 1; i < secondEnd; i++)
        {
            tape[i - (secondStart - headPosition)] = tape[i];
            tape[i] = 'B';
        }
    }
}

// Hàm thực thi máy Turing cho bài toán 4b: f(n1, n2) = max(n1, n2)
void turing4b(Tape& tape, int& headPosition) {
    int firstEnd = 0;
    int secondStart = 0;
     while (tape[headPosition] != '*')
    {
        headPosition++;
    }
    secondStart = headPosition;
    headPosition = 100;
    while (tape[headPosition] != '*')
    {
        firstEnd++;
        headPosition++;
    }
    int secondEnd = firstEnd + 1;
    while(tape[secondEnd] != 'B')
    {
        secondEnd++;
    }
    headPosition = 100;
    while (headPosition < firstEnd && secondStart + 1 < secondEnd)
    {
        tape[headPosition] = 'B';
        tape[secondStart + 1] = 'B';
        headPosition++;
        secondStart++;
    }
    if (headPosition == firstEnd)
    {
        //Do nothing
    }
    else
    {
        for (int i = secondStart + 1; i < secondEnd; i++)
        {
            tape[i - (secondStart - headPosition)] = tape[i];
            tape[i] = 'B';
        }
    }
}

// Hàm thực thi máy Turing cho bài toán 5: f(n1, n2) = n1 * n2
void turing5(Tape& tape, int& headPosition) {
    int firstEnd = 0;
    int secondStart = 0;
    while (tape[headPosition] != '*')
    {
        headPosition++;
    }
    secondStart = headPosition;
    headPosition = 100;
    while (tape[headPosition] != '*')
    {
        firstEnd++;
        headPosition++;
    }
    int secondEnd = firstEnd + 1;
    while(tape[secondEnd] != 'B')
    {
        secondEnd++;
    }
     int resultEnd = secondEnd;
     for (int i = 0; i < firstEnd; i++)
     {
        for (int j = secondStart + 1; j < secondEnd; j++)
        {
            tape[resultEnd++] = '1';
        }
     }
}

int main() {
    // Chọn bài toán để chạy
    int problem;
    cout << "Nhap so bai toan (1-5): ";
    cin >> problem;

    // Nhập dữ liệu đầu vào
    string input;
    cout << "Nhap du lieu dau vao (vi du: 111*11): ";
    cin >> input;

    // Khởi tạo băng và vị trí đầu đọc
    Tape tape = initializeTape(input);
    int headPosition = 100;

    // In băng ban đầu
    cout << "Bang ban dau: ";
    printTape(tape, headPosition);

    // Thực thi bài toán đã chọn
    switch (problem) {
        case 1:
            turing1(tape, headPosition);
            break;
        case 2:
            turing2(tape, headPosition);
            break;
        case 3:
            turing3(tape, headPosition);
            break;
        case 4:
            turing4(tape, headPosition);
            break;
        case 5:
            turing5(tape, headPosition);
            break;
        case 21:
            turing2a(tape, headPosition);
            break;
        case 22:
            turing2b(tape, headPosition);
            break;
        case 31:
            turing3b(tape, headPosition);
            break;
        case 41:
            turing4b(tape, headPosition);
            break;
        default:
            cout << "Khong co bai toan nay!" << endl;
            return 1;
    }

    // In băng kết quả
    cout << "Bang ket qua: ";
    printTape(tape, headPosition);

    return 0;
}
