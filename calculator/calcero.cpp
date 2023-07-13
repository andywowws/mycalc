#include "calcero.h"
#define ll long long
using namespace std;
void calcs::mid2last(string a){
    stack<char>signs;
    string lastf;
    for(int i=0;i<a.length();i++){
        if(a[i]>='0'&&a[i]<='9')lastf.push_back(a[i]);
        else{
            if(lastf!="")last.push(lastf);
            lastf="";
            if((a[i]=='+'||a[i]=='-')){
                while(1){
                    string s(1,a[i]);
                    if(signs.empty()||signs.top()=='(')signs.push(a[i]);
                    else if((signs.top()=='*'||signs.top()=='/'))signs.push(a[i]);
                    else{
                        s.pop_back();
                        s+=signs.top();
                        signs.pop();
                        last.push(s);
                        continue;
                    }
                    break;
                }
            }
            if((a[i]=='*'||a[i]=='/')){
                while(1){
                    string s(1,a[i]);
                    if(signs.empty()||signs.top()=='(')signs.push(a[i]);
                    else{
                        s.pop_back();
                        s+=signs.top();
                        signs.pop();
                        last.push(s);
                        continue;
                    }
                    break;
                }
            }
            if(a[i]=='('){
                signs.push('(');
            }
            if(a[i]==')'){
                while(signs.top()!='('){
                    string a(1,signs.top());
                    last.push(a);
                    signs.pop();
                }
                signs.pop();
            }
        }
    }
    if(!lastf.empty())last.push(lastf);
    while(!signs.empty()){
        string s(1,signs.top());
        last.push(s);
        signs.pop();
    }
    return;
}
string calcs::calc(){
    stack<string>ls1=last;
    stack<string>ls2;
    stack<string>datas;
    while(!ls1.empty()){
        ls2.push(ls1.top());
        ls1.pop();
    }
    while(!ls2.empty()){
        string x=ls2.top();
        if(x.front()>='0')datas.push(x);
        else{
            double s1=stod(datas.top());
            datas.pop();
            double s2=stod(datas.top());
            datas.pop();
            double res;
            if(x=="+")res=s1+s2;
            if(x=="-")res=s2-s1;
            if(x=="*")res=s1*s2;
            if(x=="/")res=s2/s1;
            ostringstream oss;
            oss<<res;
            datas.push(oss.str());
        }
        ls2.pop();
    }
    return datas.top();
}
void calcs::print(){
    stack<string>ls=last;
    stack<string>ls2;
    string coutf;
    while(!ls.empty()){
        ls2.push(ls.top());
        ls.pop();
    }
    while(!ls2.empty()){
        coutf+=ls2.top();
        coutf+=' ';
        ls2.pop();
    }
    cout<<coutf<<endl;
    return;
}