#include "LRUCache.h"

// Constructor for initializing the
 // cache capacity with the given value.
LRUCache::LRUCache(int capacity)
{
    cap = capacity;
    head->next = tail;
    tail->prev = head;
}

void LRUCache::addnode(node* temp)
{
    node* dummy = head->next;
    head->next = temp;
    temp->prev = head;
    temp->next = dummy;
    dummy->prev = temp;
}

void LRUCache::deletenode(node* temp)
{
    node* delnext = temp->next;
    node* delprev = temp->prev;
    delnext->prev = delprev;
    delprev->next = delnext;
}


int LRUCache::get(int key)
{
    if (m.find(key) != m.end())
    {
        node* res = m[key];
        m.erase(key);
        int ans = res->value;
        deletenode(res);
        addnode(res);
        m[key] = head->next;
        cout << "Got the value : " << ans
            << " for the key: " << key << "\n";
        return ans;
    }
    cout << "Did not get any value for the key: "
        << key << "\n";
    return -1;
}


void LRUCache::set(int key, int value)
{

    cout << "Going to set the (key, value) : ("
        << key << ", " << value << ")" << "\n";
    if (m.find(key) != m.end())
    {
        node* exist = m[key];
        m.erase(key);
        deletenode(exist);
    }

    if (m.size() == cap)
    {
        m.erase(tail->prev->key);
        deletenode(tail->prev);
    }
    addnode(new node(key, value));
    m[key] = head->next;
}