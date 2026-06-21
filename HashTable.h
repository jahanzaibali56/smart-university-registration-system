#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>

using namespace std;

class HashTable
{
private:
    struct HashNode
    {
        string key;
        string value;
        HashNode* next;

        HashNode(const string& k, const string& v)
        {
            key = k;
            value = v;
            next = NULL;
        }
    };

    static const int TABLE_SIZE = 101;
    HashNode* table[TABLE_SIZE];

    int hashFunction(const string& key);

public:
    HashTable();
    ~HashTable();

    void insert(const string& key, const string& value);
    bool search(const string& key, string& value);
    bool remove(const string& key);
    void clear();
};

#endif
