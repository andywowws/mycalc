#include "calcero.h"
#define ll long long
using namespace std;
void calcs::mid2last(string a){
    stack<char>signs;
    string lastf;
    for(int i=0;i<a.length();i++){
        if(a[i]=='-'){
            if(i==0){lastf.push_back(a[i]);i++;}
            else if(a[i-1]=='('){lastf.push_back(a[i]);i++;}
        }
        if((a[i]>='0'&&a[i]<='9')||a[i]=='.')lastf.push_back(a[i]);
        else{
            if(lastf[lastf.length()-1]=='.')lastf.pop_back();
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
            if((a[i]=='^')){
                while(1){
                    string s(1,a[i]);
                    if(signs.empty()||signs.top()=='(')signs.push(a[i]);
                    else if((signs.top()=='+'||signs.top()=='-'))signs.push(a[i]);
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
    try{
        while(!ls2.empty()){
            string x=ls2.top();
            if(x.front()>='0'&&x.front()<='9'||x.length()>1)datas.push(x);
            else{
                string s=datas.top();
                double s1,s2;
                stringstream ss;
                ss<<fixed<<setprecision(100)<<s;
                ss>>s1;
                ss.clear();
                ss.str("");
                datas.pop();
                if(datas.empty())(throw -1);
                s=datas.top();
                ss<<fixed<<setprecision(100)<<s;
                ss>>s2;
                ss.clear();
                ss.str("");
                datas.pop();
                double res;
                if(x=="+")res=s1+s2;
                if(x=="-")res=s2-s1;
                if(x=="*")res=s1*s2;
                if(x=="/"){
                    if(s1==0)throw -1;
                    res=s2/s1;
                }
                if(x=="^")res=pow(s2,s1);
                ss<<fixed<<setprecision(100)<<res;
                string y=ss.str();
                ss.clear();
                ss.str("");
                int pos=y.find('.');
                if(pos!=string::npos){
                    int i=y.length()-1;
                    while(y[i]=='0'&&y[i]!='.')i--;
                    if(y[i]!='0'&&y[i]!='.')i++;
                    y=y.substr(0,i);
                }
                datas.push(y);
            }
            ls2.pop();
        }
        if(datas.empty())throw -1;
        return datas.top();
    }
    catch(int e){
        printf("equation not right,exit code:%d",-1);
    }
    return "E";
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