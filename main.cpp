#include "HashTable.h"
#include "FileIO.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Usage: ./main MST.txt input.txt output.txt\n";
        return 1;
    }

    string mst_file = argv[1];
    string input_file = argv[2];
    string output_file = argv[3];

    vector<Company> companies = readCompanyList(mst_file);
    HashTable* table = createHashTable(companies);

    vector<string> queries = readCompanyNames(input_file);
    vector<Company> results;

    for (string& name : queries) {
        Company* found = search(table, name);
        if (found) results.push_back(*found);
    }

    writeCompanyInfo(output_file, results);

    delete table;
    return 0;
}
