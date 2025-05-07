#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Company.h"
#include <vector>
using namespace std;

const int TABLE_SIZE = 2000;

struct HashNode {
    Company data;
    HashNode* next;

    HashNode(Company comp) : data(comp), next(nullptr) {}
};

struct HashTable {
    HashNode* table[TABLE_SIZE];

    HashTable();
    ~HashTable();
};

long long hashString(string company_name);
void insert(HashTable* hash_table, Company company);
Company* search(HashTable* hash_table, string company_name);
HashTable* createHashTable(vector<Company> list_company);

#endif
