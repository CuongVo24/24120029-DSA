#ifndef FILEIO_H
#define FILEIO_H

#include "Company.h"
#include <vector>
#include <string>
using namespace std;

vector<Company> readCompanyList(string file_name);
vector<string> readCompanyNames(string file_name);
void writeCompanyInfo(string file_name, vector<Company> companies);

#endif
