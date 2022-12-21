#include <iostream>
#include <map>
using namespace std;

class LRUCache {

public:
    class node
    {
    public:
        int key;
        int value;
        node* prev;
        node* next;

        node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int cap;
    map<int, node*> m;

    // Constructor for initializing the
    // cache capacity with the given value.
    LRUCache(int capacity);

    void addnode(node* temp);    
    void deletenode(node* temp);
    int get(int key);
    void set(int key, int value);

 
};