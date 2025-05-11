#include <iostream>
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
}//01
struct Node {
    int value;
    Node *next;
};

Node* deleteBottom(Node* head) {
    if (!head || !head->next) return head;
    Node* prev = nullptr;
    Node* curr = head;

    while (curr->next) {
        if (curr->value < curr->next->value) { 
            if (!prev || prev->value > curr->value) {
                Node* Del = curr;
                if (prev) {
                    prev->next = curr->next;
                } else {
                    head = curr->next;
                }
                delete Del;
                return head;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

#include <iostream>
using namespace std;

void printList(Node* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int value;
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> value;
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    head = deleteBottom(head);

    printList(head);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}//02

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int BFS(int row, int col, const vector <vector<int>> &grid, vector <vector<int>> &visited, int N){
    if(row < 0 || row >= N || col < 0 || col >= N || visited[row][col] || grid[row][col]){
        return 0;
    }
    int area = 1;
    visited[row][col] = 1;
    int qx[] = {0,1,0,-1};
    int qy[] = {1,0,-1,0};
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextrow = curr.first + qx[i];
            int nextcol = curr.second + qy[i];
            
            if(nextrow >= 0 && nextrow < N && nextcol >= 0 && nextcol < N && !grid[nextrow][nextcol] && !visited[nextrow][nextcol]){
                visited[nextrow][nextcol] = 1;
                area ++;
                q.push({nextrow,nextcol});
            }
        }
    }
    return area;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>>grid(N, vector<int>(N,0));
    vector<vector<int>>visited(N,vector<int>(N,0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }   
    }
    int maxarea = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int area = BFS(i,j,grid,visited,N);
            if(maxarea < area){maxarea = area;}
        }
        
    }
    cout << maxarea;
    return 0;
}//03

