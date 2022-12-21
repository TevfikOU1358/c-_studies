#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <stdexcept>
#include "LRUCache.h"
//Add header files here.
using namespace std;

//Modify this file only to add necessary header files.
//Do not modify main function.
int main() {
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    try {
        if ((n < 1 || n > 500000 ) || (capacity < 1 || capacity > 1000))
            throw std::out_of_range{ "*******range out********" };
    }
    catch (const exception& e) {
        cout << "Exception caught:" << e.what() << "\n";
        abort();
    }
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            try {
                if ((key < 1 || key > 20) || (value < 1 || value > 2000))
                    throw std::out_of_range{ "*******range out********" };
            }
            catch (const exception& e) {
                cout << "Exception caught:" << e.what() << "\n";
                abort();
            }
            l.set(key, value);
        }
    }
    return 0;
}