#include "FileIO.h"
#include <fstream>
#include <sstream>

vector<Company> readCompanyList(string file_name) {
    vector<Company> companies;
    ifstream in(file_name);
    string line;
    getline(in, line); // Bỏ dòng tiêu đề

    while (getline(in, line)) {
        stringstream ss(line);
        string name, tax, address;

        getline(ss, name, '|');
        getline(ss, tax, '|');
        getline(ss, address);

        companies.push_back({ name, tax, address });
    }

    return companies;
}

vector<string> readCompanyNames(string file_name) {
    vector<string> names;
    ifstream in(file_name);
    string name;

    while (getline(in, name)) {
        if (!name.empty())
            names.push_back(name);
    }

    return names;
}

void writeCompanyInfo(string file_name, vector<Company> companies) {
    ofstream out(file_name);
    for (const Company& c : companies) {
        out << c.name << "|" << c.profit_tax << "|" << c.address << "\n";
    }
}
