/*************************************************************************
Design, develop, and execute a program in C++ to create a class
called STACK using an array of integers and to implement the
following operations by overloading the operators + and - :
i. s1=s1 + element; where s1 is an object of the class STACK
and element is an integer to be pushed on to top of the
stack.
ii. s1=s1- ; where s1 is an object of the class STACK and –
operator pops off the top element.
Handle the STACK Empty and STACK Full conditions. Also
display the contents of the stack after each operation, by overloading
the operator <<.
*************************************************************************/

#include <iostream>

using namespace std;

int top=0;

class stack
{
	public:
        int a[100],n;
		stack()
		{
            cout<<"Enter the size of the stack\n";
            cin>>n;
            top=0;
		}
		stack operator + (int);
		stack operator -- ();
		friend ostream& operator <<(ostream &,stack );

}s1;

int main()
{
	int choice=0;
    for(;;)
	{
        cout<<"\nEnter Your Choice \n 1.Push\n 2.Pop\n 3.Display\n 4.Exit\n";
		cin>>choice;
		switch(choice)
		{
		case 1:cout<<"\nEnter The Element : ";
            int e;
			cin>>e;
			s1 = s1 + e;
			break;
		case 2:s1 = --s1;
			break;
		case 3:cout<<s1;
			break;
		case 4:return 0;
		}
	}
}

stack stack::operator +(int x)
{
	if(top==n)
	{
		cout<<"\nstack Overflow";
	}
    else
        a[top++]=x;
	return *this;
}


stack stack::operator --()
{
	if(top==0)
	{
		cout<<"\nstack empty\n";
	}
    else
        cout<<"\nElement popped \t"<<a[--top]<<"\n";
	return *this;
}


ostream& operator <<(ostream &out,stack r)
{
    out<<"Elements are \n";
    for(int i=0 ; i<top ; i++)
    {
        out<<s1.a[i]<<"\t";
    }
    out<<"\n";
    return out;
}

/**
	Author - Aman
*/
