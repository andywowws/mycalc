#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
class calcbase {
public:
    static string add(string a, string b, bool xs);
    static string sub(string a, string b, bool xs);
    static string mcl(string a, string b);
    static string div(string a, ll b);
};