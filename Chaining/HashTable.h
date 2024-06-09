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

template <class T>
struct  hash_function{
    size_t operator()(const T& key) const {
        return hash<T>()(key);
    }
};

template <>
struct hash_function<string>{
    size_t operator()(const string& key) const{
        size_t hash = 0;
        for(auto c:key) hash = hash*31+c;
        return hash;
    }
};

template <class T, class U, class V = hash_function<T>>
class HashTable{
private:
    struct Item{
        T key;
        T value;
    };
    LinkedList<Item*>* table;
    int sz;

    int hash(const T& key){
        return hash_function(key) % sz;
    }

public:
    explicit HashTable(int _sz): sz(_sz){
        table = new LinkedList<Item*>*[_sz];
    }

};



#endif //HW3_HASH_TABLE_HASHTABLE_H
