#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

void prefixEval(string s){
    stack<int> st;
    for(int i=((s.length())-1);i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push((s[i]-'0'));
        }
        else{
            int operand1=st.top();
            st.pop();
            int operand2=st.top();
            st.pop();
            if(s[i]=='+'){
            st.push((operand1+operand2));
        }
        if(s[i]=='-'){
            st.push((operand1-operand2));
        }
        if(s[i]=='*'){
            st.push((operand1*operand2));
        }
        if(s[i]=='/'){
            st.push((operand1/operand2));
        }
        if(s[i]=='^'){
            st.push((pow(operand1,operand2)));
        }
        }
    }
    cout<<st.top();
}

int main(){
    string s;
    s="-+7*45+20";
    prefixEval(s);
    return 0;
}