#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct node<T> * first;
        int count;
    
    public:
        DoublyLL();
        void insertfirst(T no);
        void display();
        int CountNode();
        void insertlast(T no);
        void deletefirst();
        void deletelast();
        void insertatpos(T no, int ipos);
        void deleteatpos(int ipos);

};

template<class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    count = 0;
}

template<class T>
void DoublyLL<T> :: insertfirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    count++;
}

template<class T>
void DoublyLL<T> :: insertlast(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        struct node<T> * temp = first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
         temp->next = newn;
         newn->prev = temp;    
    }
    count++;
}

template<class T>
void DoublyLL<T> :: deletefirst()
{

    if(first == NULL)
    {
        return;
    }
    else if((first->next == NULL )&& (first -> prev == NULL))
    {
        delete first;
        first = NULL;
    }
    else
    {   

        first = first->next;
        delete(first->prev);
        first->prev = NULL;
    }
    count--;
}

template<class T>
void DoublyLL<T> :: deletelast()
{
    if(first == NULL )
    {
        return;
    }
    else if((first->next == NULL) && (first->prev == NULL))
    {
        delete first;
        first = NULL;
    }
    else 
    {
        struct node<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    count--; 
}

template<class T>
void DoublyLL<T>::display()
{
    struct node<T> *temp = first;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


template<class T>
int DoublyLL<T> :: CountNode()
{
    return count;
}

template<class T>
void DoublyLL<T> :: insertatpos(T no, int ipos)
{
    if(ipos < 1 || ipos > count + 1)
    {
        cout<<"invalid postion\n";
        return;
    }

    if(ipos == 1)
    {
        insertfirst(no);
    }
    else if(ipos == count)
    {
        insertlast(no);
    }
    else 
    {   int i = 0;
        struct node<T> * temp = first;
        struct node<T> * newn = NULL;
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
    count++;
}

template<class T>
void DoublyLL<T> :: deleteatpos(int ipos)
{
    if(ipos < 1 || ipos > count)
    {
        cout<<"invalid postion\n";
        return;
    }

    if(ipos == 1)
    {
        deletefirst();
    }
    else if(ipos == count)
    {
        deletelast();
    }
    else
    {
        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
    }
    count--; 
}

int main()
{
    DoublyLL<int> iobj;
    DoublyLL<float> fobj;
    DoublyLL<double> dobj;
    DoublyLL<char> cobj;
    
    iobj.insertfirst(101);
    iobj.insertfirst(51);
    iobj.insertfirst(21);
    iobj.insertfirst(11);

    cout<<"LinkedList of Integers : "<<"\n";
    iobj.display();

    fobj.insertfirst(101.99);
    fobj.insertfirst(51.99);
    fobj.insertfirst(21.99);
    fobj.insertfirst(11.99);

    cout<<"\nLinkedList of floats : "<<"\n";
    fobj.display();

    dobj.insertfirst(101.999);
    dobj.insertfirst(51.999);
    dobj.insertfirst(21.999);
    dobj.insertfirst(11.999);

    cout<<"\nLinkedList of Doubles : "<<"\n";
    dobj.display();


    cobj.insertfirst('D');
    cobj.insertfirst('C');
    cobj.insertfirst('B');
    cobj.insertfirst('A');

    cout<<"\nLinkedList of Characters : "<<"\n";
    cobj.display();





    return 0;
}

