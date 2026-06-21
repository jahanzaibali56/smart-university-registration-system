#include "HashTable.h"

HashTable::HashTable()
{
    for(int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

HashTable::~HashTable()
{
    clear();
}

int HashTable::hashFunction(const string& key)
{
    int hash = 0;

    for(size_t i = 0; i < key.length(); i++)
        hash = (hash * 31 + key[i]) % TABLE_SIZE;

    return hash;
}

void HashTable::insert(const string& key, const string& value)
{
    int index = hashFunction(key);
    HashNode* temp = table[index];

    while(temp != NULL)
    {
        if(temp->key == key)
        {
            temp->value = value;
            return;
        }

        temp = temp->next;
    }

    HashNode* newNode = new HashNode(key, value);
    newNode->next = table[index];
    table[index] = newNode;
}

bool HashTable::search(const string& key, string& value)
{
    int index = hashFunction(key);
    HashNode* temp = table[index];

    while(temp != NULL)
    {
        if(temp->key == key)
        {
            value = temp->value;
            return true;
        }

        temp = temp->next;
    }

    return false;
}

bool HashTable::remove(const string& key)
{
    int index = hashFunction(key);
    HashNode* temp = table[index];
    HashNode* prev = NULL;

    while(temp != NULL)
    {
        if(temp->key == key)
        {
            if(prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            delete temp;
            return true;
        }

        prev = temp;
        temp = temp->next;
    }

    return false;
}

void HashTable::clear()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        HashNode* temp = table[i];

        while(temp != NULL)
        {
            HashNode* del = temp;
            temp = temp->next;
            delete del;
        }

        table[i] = NULL;
    }
}
