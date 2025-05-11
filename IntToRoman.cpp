#include <stdio.h>
#include <string>
using namespace std;

class solution{
    string IntToRAU(int a){
        int Mcts = a/1000;
        string result = "";
        for (int i = 0; i < Mcts; i++)
        {
                result += 'M';
        }
        
    }
    
}