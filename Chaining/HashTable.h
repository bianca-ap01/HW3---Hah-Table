//
// Created by bianca on 08/06/24.
//

#ifndef HW3_HASH_TABLE_HASHTABLE_H
#define HW3_HASH_TABLE_HASHTABLE_H
#include "LinkedList.h"
#include <type_traits>
#include <cstdint>
#include <string>
using namespace std;

template<typename T>
struct hash_function;

template <typename T>
struct hash_function {
    size_t operator()(const T& key) const {
        return reinterpret_cast<size_t>(&key);
    }
};

template <>
struct hash_function<std::string> {
    size_t operator()(const std::string& key) const {
        size_t hash = 0;
        for (char c : key) hash = hash * 31 + c;
        return hash;
    }
};

template <class T, class U, class V = hash_function<T>>
class HashTable{
private:
    struct Item{
        T key;
        U value;
    };

    LinkedList<Item*>* table;
    int sz;
    V hash_function;

    int hash(const T& key){
        return hash_function(key) % sz;
    }

public:
    explicit HashTable(): sz(71){
        table = new LinkedList<Item*>*[71];
    }

    explicit HashTable(int _sz): sz(_sz){
        table = new LinkedList<Item*>*[_sz];
    }

    void insert(T key, U value){
        auto item = new Item();
        item.key = hash(key);
        item.value = value;
        for(int i = 0; i < sz; i++){
            if(table[i] == item.key){
                table[i].insert(item);
                return;
            }
        }
    }

    void remove(T key){
        auto rem = hash(key);
        for(int i = 0; i < sz; i++){
            if(table[i] == rem){
                table[i].remove_value(key);
            }
        }
    }

};



#endif //HW3_HASH_TABLE_HASHTABLE_H
