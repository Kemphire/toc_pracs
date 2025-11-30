#include<iostream>
#include<string>
using namespace std;

bool FA1(const string &s){
    for(char c:s){
        if(c=='a')return true;
        else if(c!='b')return false;
    }
    return false;
}

bool FA2(const string &s){
    if(s.empty())return false;
    for(char c:s){
        if(c!='a'&&c!='b')return false;
    }
    return s.back()=='b';
}

bool FA_union(const string &s){
    return FA1(s)||FA2(s);
}

bool FA_intersection(const string &s){
    return FA1(s)&&FA2(s);
}

bool FA_concatenation(const string &s){
    for(size_t i=0;i<=s.size();++i){
        string x=s.substr(0,i);
        string y=s.substr(i);
        if(FA1(x)&&FA2(y))return true;
    }
    return false;
}

int main(){
    string s;
    cout<<"Enter string (over {a,b}): ";
    while(cin>>s){
        cout<<"\nFA1 (at least one 'a'): "<<(FA1(s)?"Accepted":"Rejected")<<endl;
        cout<<"FA2 (ends with 'b'): "<<(FA2(s)?"Accepted":"Rejected")<<endl;
        cout<<"Union (FA1 ? FA2): "<<(FA_union(s)?"Accepted":"Rejected")<<endl;
        cout<<"Intersection (FA1 n FA2): "<<(FA_intersection(s)?"Accepted":"Rejected")<<endl;
        cout<<"Concatenation (FA1 ° FA2): "<<(FA_concatenation(s)?"Accepted":"Rejected")<<endl;
        cout<<"\nEnter string: ";
    }
    return 0;
}

