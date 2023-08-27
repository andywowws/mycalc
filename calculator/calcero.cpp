#include "calcero.h"
#include "calcbase.h"
#include <map>
#define ll long long
using namespace std;
void calcs::mid2last(string a) {
    stack<char> signs;
    string lastf;
    map<char, int> t;
    t['+'] = 1, t['-'] = 1, t['*'] = 2, t['/'] = 2, t['^'] = 3;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '-') {
            if (i == 0) {
                lastf.push_back(a[i]);
                i++;
            } else if (a[i - 1] == '(') {
                lastf.push_back(a[i]);
                i++;
            }
        }
        if ((a[i] >= '0' && a[i] <= '9') || a[i] == '.')
            lastf.push_back(a[i]);
        else {
            if (lastf[lastf.length() - 1] == '.') lastf.pop_back();
            if (lastf != "") last.push(lastf);
            lastf = "";
            if (a[i] == '(')
                signs.push('(');
            else if (a[i] == ')') {
                while (!(signs.top() == '(' || signs.empty())) {
                    last.push(string(1, signs.top()));
                    signs.pop();
                }
                if (!signs.empty()) signs.pop();
            } else {
                if (signs.empty())
                    signs.push(a[i]);
                else {
                    while (!(t.empty() || t[signs.top()] < t[a[i]] ||
                             signs.top() == '(')) {
                        last.push(string(1, signs.top()));
                        signs.pop();
                    }
                    signs.push(a[i]);
                }
            }
        }
    }
    if (!lastf.empty()) last.push(lastf);
    while (!signs.empty()) {
        string s(1, signs.top());
        last.push(s);
        signs.pop();
    }
    return;
}
inline pair<double, int> read(string st1) {
    stringstream ss;
    int pos, w1;
    double s1;
    pos = st1.find('.');
    if (pos != string::npos)
        w1 = st1.length() - 1 - pos;
    else
        w1 = 0;
    ss << fixed << setprecision(w1) << st1;
    ss >> s1;
    ss.clear();
    ss.str("");
    return make_pair(s1, w1);
}
string calcs::calc() {
    stack<string> ls1 = last;
    stack<string> ls2;
    stack<string> datas;
    while (!ls1.empty()) {
        ls2.push(ls1.top());
        ls1.pop();
    }
    try {
        while (!ls2.empty()) {
            string x = ls2.top();
            if (x.front() >= '0' && x.front() <= '9' || x.length() > 1)
                datas.push(x);
            else {
                string st1 = datas.top();
                double s1, s2;
                int w1, w2, wr, pos;
                datas.pop();
                pair<double, int> ret = read(st1);
                s1 = ret.first, w1 = ret.second;
                if (datas.empty()) (throw -1);
                string st2 = datas.top();
                ret = read(st2);
                s2 = ret.first, w2 = ret.second;
                datas.pop();
                double res;
                string y;
                if (x == "+") {
                    y = calcbase::add(st1, st2, 0);
                }
                if (x == "-") {
                    y = calcbase::sub(st2, st1, 0);
                }
                if (x == "*") {
                    y = calcbase::mcl(st1, st2);
                }
                if (x == "/") {
                    if (s1 == 0) throw -1;
                    res = s2 / s1;
                    wr = s1 + s2 + 1;
                }
                if (x == "^") {
                    res = pow(s2, s1);
                    wr = -1;
                }
                stringstream ss;
                if (wr == -1)
                    ss << fixed << setprecision(50) << res;
                else
                    ss << fixed << setprecision(wr) << res;
                if (x == "/" || x == "^") y = ss.str();
                ss.clear();
                ss.str("");
                int pos2 = y.find('.');
                if (pos2 != string::npos) {
                    int i = y.length() - 1;
                    while (y[i] == '0' && y[i] != '.') i--;
                    if (y[i] != '0' && y[i] != '.') i++;
                    y = y.substr(0, i);
                }
                datas.push(y);
            }
            ls2.pop();
        }
        if (datas.empty()) throw -1;
        return datas.top();
    } catch (int e) {
        printf("equation not right,exit code:%d", -1);
    }
    return "E";
}
string calcs::rmbrt(string a) {
    stack<kh> brts;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '(') {
            kh k;
            k.c = a[i];
            k.pos = i;
            brts.push(k);
        }
        if (a[i] == ')') {
            kh k;
            k.c = a[i];
            k.pos = i;
            if (brts.empty())
                brts.push(k);
            else if (brts.top().c == '(')
                brts.pop();
            else
                brts.push(k);
        }
    }
    while (!brts.empty()) {
        a[brts.top().pos] = '&';
        brts.pop();
    }
    for (auto it = a.begin(); it != a.end(); it++)
        if (*it == '&') {
            a.erase(it);
            it--;
        }
    return a;
}
void calcs::print() {
    stack<string> ls = last;
    stack<string> ls2;
    string coutf;
    while (!ls.empty()) {
        ls2.push(ls.top());
        ls.pop();
    }
    while (!ls2.empty()) {
        coutf += ls2.top();
        coutf += ' ';
        ls2.pop();
    }
    cout << coutf << endl;
    return;
}