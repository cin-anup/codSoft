#include<iostream>
using namespace std;

int main(){
    float num1,num2;
    cout<<"Enter two numbers:";
    cin>>num1>>num2;
    char operations;
    cout<<"Enter a operator(+,-,*,/):";
    cin>>operations;

    switch(operations){
         case '+':
         cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl;
         break;
         case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if(num2 != 0)
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            else
                cout << "Mathematical error" << endl;
            break;
        default:
            cout << "Syntax error" << endl;
            break;
    }



    return 0;
}