#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int postfixEval(string &str){
    stack<int> st;
    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){
            st.push(str[i]-'0');
        }
        else{
            int operand2=st.top();
            st.pop();
            int operand1=st.top();
            st.pop();
            if(str[i]=='+'){
                st.push(operand1+operand2);
            }
            if(str[i]=='-'){
                st.push(operand1-operand2);
            }
            if(str[i]=='/'){
                if(operand2==0){
                    cout<<"Division by zero error\n";
                    return -1;
                }
                st.push(operand1/operand2);
            }
            if(str[i]=='*'){
                st.push(operand1*operand2);
            }
            if(str[i]=='^'){
                st.push(pow(operand1,operand2));
            }
        }
    }
    return st.top();
}

int main(){
    string s="231*+9-";
    cout<<postfixEval(s);
    return 0;
}