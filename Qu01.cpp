#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Solution(vector <int> N){
    int start = 1e7;
    int index = 0;
    for(const int& i : N){
        if(i < start){cout << index <<' ';}
        start = i;
        index++;
    }
}

int main(){
    freopen("D:\\Repo\\Practices\\input.txt", "r", stdin);
    freopen("D:\\Repo\\Practices\\output.txt", "w", stdout);


    int n;
    cin >> n;
    vector <int> N; 
    for(int i = 0; i < n; i ++){
        int tmp;
        cin >> tmp;
        N.push_back(tmp);
    }

    Solution(N);
    return 0;
}