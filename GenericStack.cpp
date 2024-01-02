#include<iostream>
using namespace std;

template<class T>
struct node
{
    T Data;
    struct node *next;
};

template<class T>
class Stack
{
    private:
        struct node<T> * Head;
    public:
        Stack();
        void Push(T no);
        int POP();
        void Display();

};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
}

template<class T>
void Stack<T> :: Push(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>();

    newn->Data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }

}

template<class T>
int Stack<T> :: POP()
{
    struct node<T> * temp = Head;
    int value = 0;

    if(Head == NULL)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        value = Head->Data;
        Head = Head->next;
        delete(temp);
    }

    return value;
}

template<class T>
void Stack<T> :: Display()
{
    cout<<"\nElements of Stack are : \n";

    struct node<T> * temp = Head;

    while(temp != NULL)
    {
        cout<<" | "<< temp->Data <<" | ";
        temp = temp->next;\
    }

}


int main()
{
    Stack<int> iobj;
    Stack<float> fobj;
    Stack<double> dobj;
    Stack<char> cobj;

    int iRet = 0;

    iobj.Push(101);
    iobj.Push(51);
    fobj.Push(21.99);
    fobj.Push(11.99);
    dobj.Push(21.999);
    dobj.Push(11.99);
    cobj.Push('B');
    cobj.Push('A');
    
    iobj.Display();
    fobj.Display();
    dobj.Display();
    cobj.Display();

    return 0;

}