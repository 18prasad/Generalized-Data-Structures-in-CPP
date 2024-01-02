#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class Queue
{
    private:
        struct node<T> * Head;
    
    public:
        Queue();
        void Enqueue(T no);
        int Dequeue();
        void Display();
        ~Queue();
};

template <class T>
Queue<T>::Queue()
{
    Head = NULL;
}

template <class T>
void Queue<T>::Enqueue(T no)
{
    struct node<T> * newn = new struct node<T>();
    
    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T> * temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

template <class T>
int Queue<T> :: Dequeue()
{
    int value = 0;

    if(Head == NULL)
    {
        cout<<"Queue is empty\n";
        return value;
    }
    else
    {
        struct node<T> * temp = Head;
        value = Head->data;
        Head = Head->next;
        delete temp;
    }

    return value;

}

template <class T>
void Queue<T> :: Display()
{
    cout<<"\nElements of the Queue are : \n";

    struct node<T> * temp = Head;

    while(temp != NULL)
    {
        cout<<" | " <<temp->data<< " | ";
        temp = temp->next;
    }

}

template <class T>
Queue<T>::~Queue()
{
    while(Head != NULL)
    {
        struct node<T> * temp = Head;
        Head = Head->next;
        delete temp;
    }

}

int main()
{
    Queue<int> iobj;
    Queue<float> fobj;
    Queue<double> dobj;
    Queue<char> cobj;

    int iRet = 0;

    iobj.Enqueue(11);
    iobj.Enqueue(21);
    fobj.Enqueue(51.99);
    fobj.Enqueue(101.99);
    dobj.Enqueue(101.999);
    dobj.Enqueue(111.999);
    cobj.Enqueue('A');
    cobj.Enqueue('B');
  

    iobj.Display();
    fobj.Display();
    dobj.Display();
    cobj.Display();

    return 0;

}