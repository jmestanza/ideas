#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};



class LRUCache: public Cache {
public:
    LRUCache(int capacity){
        cp = capacity;
    }

    void emptyCache(Node * new_head){
        head = new_head;
        tail = new_head;
    }

    void popTail(){
        Node * new_tail = tail->prev;
        mp.erase(tail->key);
        delete tail;
        tail = new_tail;
    }

    void insertNewHead(Node * new_head){
        new_head->next = head;
        head->prev = new_head;
        head = new_head;
    }

    bool isHead(Node * current){
        return current->prev == NULL;
    }

    bool isTail(Node * current){
        return current->next == NULL;
    }

    void set(int key, int value){
        if(get(key) == -1){
            // no node with this key exists
            Node * new_head = new Node(key, value);
            mp.emplace(key,new_head);

            if(mp.size() == 1){
                emptyCache(new_head);
            } else {
                insertNewHead(new_head);
                if(mp.size() == cp){
                    popTail();
                }
            }

        } else {
            // if exists, must grab it and get it to the front
            Node * curr = mp.find(key)->second;

            if(mp.size() == 1){ // if it's the only item
                // just set the value
                curr->value = value;
            } else {
                if(isHead(curr)){
                    // don't move, just update value
                  curr->value = value;
                } else if(isTail(curr)){
                    curr->value = value;
                    curr->prev->next = NULL;
                    tail = curr->prev;
                    insertNewHead(curr);
                } else {
                    curr->value = value;
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    insertNewHead(curr);
                }
            }
        }
    }

    int get(int key){
        auto search_it = mp.find(key);
        if(search_it != mp.end()){
            // found in cache
            return search_it->second->value;
        } else {
            return -1;
        }
    }
};

int main() {
    int n, capacity,i;

    cin >> n >> capacity;

    vector<string> commands;
    vector<int> keys;
    vector<int> values;

    // take input
    for(i=0;i<n;i++) {
        string command;
        cin >> command;
        commands.push_back(command);
        int key, value;
        if(command == "get"){
            cin >> key;
        } else if (command == "set"){
            cin >> key >> value;
        }
        keys.push_back(key);
        values.push_back(value);
    }

    FILE *fout;
    fout = freopen("../output.txt","w",stdout);

    // process
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
        string command = commands[i];
        if(command == "get") {
            int key = keys[i];
            cout << l.get(key) << endl;
        }
        else if(command == "set") {
            int key = keys[i];
            int value = values[i];
            l.set(key,value);
        }
    }

    // give answer


    fclose(fout);
    return 0;
}
