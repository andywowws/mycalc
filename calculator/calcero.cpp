#include "calcero.h"
#include "calcbase.h"
#define ll long long
using namespace std;
void calcs::mid2last(string a)
{
    stack<char> signs;
    string lastf;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '-')
        {
            if (i == 0)
            {
                lastf.push_back(a[i]);
                i++;
            }
            else if (a[i - 1] == '(')
            {
                lastf.push_back(a[i]);
                i++;
            }
        }
        if ((a[i] >= '0' && a[i] <= '9') || a[i] == '.')
            lastf.push_back(a[i]);
        else
        {
            if (lastf[lastf.length() - 1] == '.')
                lastf.pop_back();
            if (lastf != "")
                last.push(lastf);
            lastf = "";
            if ((a[i] == '+' || a[i] == '-'))
            {
                while (1)
                {
                    string s(1, a[i]);
                    if (signs.empty() || signs.top() == '(')
                        signs.push(a[i]);
                    else if ((signs.top() == '*' || signs.top() == '/'))
                        signs.push(a[i]);
                    else
                    {
                        s.pop_back();
                        s += signs.top();
                        signs.pop();
                        last.push(s);
                        continue;
                    }
                    break;
                }
            }
            if ((a[i] == '*' || a[i] == '/'))
            {
                while (1)
                {
                    string s(1, a[i]);
                    if (signs.empty() || signs.top() == '(')
                        signs.push(a[i]);
                    else
                    {
                        s.pop_back();
                        s += signs.top();
                        signs.pop();
                        last.push(s);
                        continue;
                    }
                    break;
                }
            }
            if ((a[i] == '^'))
            {
                while (1)
                {
                    string s(1, a[i]);
                    if (signs.empty() || signs.top() == '(')
                        signs.push(a[i]);
                    else if ((signs.top() == '+' || signs.top() == '-'))
                        signs.push(a[i]);
                    else
                    {
                        s.pop_back();
                        s += signs.top();
                        signs.pop();
                        last.push(s);
                        continue;
                    }
                    break;
                }
            }
            if (a[i] == '(')
            {
                signs.push('(');
            }
            if (a[i] == ')')
            {
                while (signs.top() != '(')
                {
                    string a(1, signs.top());
                    last.push(a);
                    signs.pop();
                }
                signs.pop();
            }
        }
    }
    if (!lastf.empty())
        last.push(lastf);
    while (!signs.empty())
    {
        string s(1, signs.top());
        last.push(s);
        signs.pop();
    }
    return;
}
string calcs::calc()
{
    stack<string> ls1 = last;
    stack<string> ls2;
    stack<string> datas;
    while (!ls1.empty())
    {
        ls2.push(ls1.top());
        ls1.pop();
    }
    try
    {
        while (!ls2.empty())
        {
            string x = ls2.top();
            if (x.front() >= '0' && x.front() <= '9' || x.length() > 1)
                datas.push(x);
            else
            {
                string st1 = datas.top();
                double s1, s2;
                int w1, w2, wr, pos;
                pos = st1.find('.');
                if (pos != string::npos)
                    w1 = st1.length() - 1 - pos;
                else
                    w1 = 0;
                stringstream ss;
                ss << fixed << setprecision(w1) << st1;
                ss >> s1;
                ss.clear();
                ss.str("");
                datas.pop();
                if (datas.empty())
                    (throw -1);
                string st2 = datas.top();
                pos = st2.find('.');
                if (pos != string::npos)
                    w2 = st2.length() - 1 - pos;
                else
                    w2 = 0;
                ss << fixed << setprecision(w2) << st2;
                ss >> s2;
                ss.clear();
                ss.str("");
                datas.pop();
                double res;
                int n = 0;
                if (x == "+")
                {
                    res = s1 + s2;
                    n = 1;
                    wr = max(w1, w2);
                }
                if (x == "-")
                {
                    res = s2 - s1;
                    n = 2;
                    wr = max(w1, w2);
                }
                if (x == "*")
                {
                    res = s1 * s2;
                    wr = w1 + w2;
                }
                if (x == "/")
                {
                    if (s1 == 0)
                        throw -1;
                    res = s2 / s1;
                    wr = s1 + s2 + 1;
                }
                if (x == "^")
                {
                    res = pow(s2, s1);
                    wr = -1;
                }
                if (wr == -1)
                    ss << fixed << setprecision(50) << res;
                else
                    ss << fixed << setprecision(wr) << res;
                string y = ss.str();
                calcbase base1;
                if (n == 1)
                    y = base1.add(st1, st2, 0);
                if (n == 2)
                    y = base1.sub(st2, st1, 0);
                ss.clear();
                ss.str("");
                int pos2 = y.find('.');
                if (pos2 != string::npos)
                {
                    int i = y.length() - 1;
                    while (y[i] == '0' && y[i] != '.')
                        i--;
                    if (y[i] != '0' && y[i] != '.')
                        i++;
                    y = y.substr(0, i);
                }
                datas.push(y);
            }
            ls2.pop();
        }
        if (datas.empty())
            throw -1;
        return datas.top();
    }
    catch (int e)
    {
        printf("equation not right,exit code:%d", -1);
    }
    return "E";
}
string calcs::rmbrt(string a)
{
    stack<kh> brts;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '(')
        {
            kh k;
            k.c = a[i];
            k.pos = i;
            brts.push(k);
        }
        if (a[i] == ')')
        {
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
    while (!brts.empty())
    {
        a[brts.top().pos] = '&';
        brts.pop();
    }
    for (auto it = a.begin(); it != a.end(); it++)
        if (*it == '&')
        {
            a.erase(it);
            it--;
        }
    return a;
}
void calcs::print()
{
    stack<string> ls = last;
    stack<string> ls2;
    string coutf;
    while (!ls.empty())
    {
        ls2.push(ls.top());
        ls.pop();
    }
    while (!ls2.empty())
    {
        coutf += ls2.top();
        coutf += ' ';
        ls2.pop();
    }
    cout << coutf << endl;
    return;
}