#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <queue>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#define ll long long
using namespace std;
class kh
{
public:
    char c;
    int pos;
};
class calcs
{
public:
    void mid2last(string a);
    string calc();
    void print();
    string rmbrt(string a);

private:
    stack<string> last;
};