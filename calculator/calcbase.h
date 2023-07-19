#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
class calcbase
{
public:
    string add(string a, string b, bool xs);
    string sub(string a, string b, bool xs);
    string mcl(string a, string b);
    string div(string a, ll b);
};