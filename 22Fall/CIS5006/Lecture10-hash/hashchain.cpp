//cpp program to implement hashing with chaining

#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int BUCKET; //number of buckets
    
    list<int> *table;
public:
    Hash(int V);

    void insertItem(int key);
    void deleteItem(int key);
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    int index = hashFunction(key);
    //find the key in (index)th list;
    list <int> :: iterator i;
    for (i = table[index].begin(); i!=table[index].end();i++)
    {
        if (*i == key)
            break;
    }
    //if key is found in hash table, remove it.
    if (i!=table[index].end())
    {
        table[index].erase(i);
    }
}

void Hash::displayHash()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x:table[i])
            cout <<" --> " << x;
        cout <<endl;
    }
}