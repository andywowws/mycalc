#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
#define ll long long
using namespace std;
class calcs{
    public:
        void mid2last(string a);
        string calc();
        void print();
    private:
        stack<string> last;
};