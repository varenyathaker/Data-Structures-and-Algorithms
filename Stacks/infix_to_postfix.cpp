

#include <bits/stdc++.h>
using namespace std;

class Stack {
    int size;
    int* arr;
    int top;
public:
    Stack() {
        size = 100;
        arr = new int[size];
        top = -1;
    }
    void push(int x) {
        top++;
        arr[top] = x;
    }
    int pop() {
        int x = arr[top];
        top--;
        return x;
    }
    int topelement() {
        return arr[top];
    }
    int sizeofstack() {
        return top + 1;
    }
};

// function for operator precedence
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// function to convert infix to postfix
void infixtopostfix(string s) {
    Stack st;
    string ans;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // If character is an operand, add it to the result
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            ans += ch;
        }
        // If character is '(', push it to the stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If character is ')', pop until '(' is found
        else if (ch == ')') {
            while (st.sizeofstack()!=0 and st.topelement()!='(') {
                ans += st.topelement();
                st.pop();
            }
            // Pop '(' as well
            if (st.sizeofstack() != 0) {
                st.pop();
            }
        }
        // If character is an operator
        else {
            while (st.sizeofstack() != 0 && prec(ch) <= prec(st.topelement())) {
                ans += st.topelement();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators in the stack
    while (st.sizeofstack() != 0) {
        ans += st.topelement();
        st.pop();
    }

    cout << ans << endl;
}

int main() {
    string str = "(p*q)+(m-n)";
    infixtopostfix(str);
    return 0;
}
