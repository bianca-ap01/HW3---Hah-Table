#include <iostream>
#include "hash_table.h"
using namespace std;

int main() {
    hash_table<char,int> table;
    table['a']=1;
    table['b']=2;
    table['c']=3;
    table['d']=4;
    table['e']=5;

    table.remove('a');

    cout<<table['a']<<endl;
    cout<<table['b']<<endl;
    cout<<table['c']<<endl;
    cout<<table['d']<<endl;
    cout<<table['e']<<endl;
}
