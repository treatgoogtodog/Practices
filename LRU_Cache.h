#include <unordered_map>
//Least Recently Used Cache in Linked List Style

struct Node
{
    int value;
    int key;
    Node* next, prev;
    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
    Node(Node* prev, int key, int value) : prev(prev), key(key), value(value), next(nullptr) {}
};


class LRUCache{
public:
    LRUCache(int capacity){

    }
private:
    int capacity;
    int currentSize;
    std::unordered_map<int, Node*> CacheMap;
    Node* tail, head;    
}