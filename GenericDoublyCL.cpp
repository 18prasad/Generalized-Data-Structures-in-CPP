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
class DoublyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int count;
    public:
        DoublyCL();
        void insertfirst(T no);
        void insertlast(T no);
        void deletefirst();
        void deletelast();
        void insertatpos(T no, int ipos);
        void deleteatpos(int ipos);
        void display();
        int CountNode();

        
};

template<class T>
DoublyCL<T> :: DoublyCL()
{
    first = NULL;
    last = NULL;
    count = 0;
}

template<class T>
void DoublyCL<T> ::insertfirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
        
        
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;     
    }

        last->next = first;
        first->prev = last;
        count++; 
}

template<class T>
void DoublyCL<T> :: insertlast(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;
    count++;


}

template<class T>
void DoublyCL<T> :: deletefirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if (first == NULL)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;

        last->next = first;
        first->prev = last;
    }
   
   count--;

}

template<class T>
void DoublyCL<T> :: deletelast()
{
   
   if((first == NULL) && (last == NULL))
   {
        return;
   }
   else if (first == last)
   {
        delete first;
        first = NULL;
        last = NULL;
   }
   else
   {
        last = last->prev;
        delete last->next;

        last->next = first;
        first->prev = last;

   }

   count--;
    
}

template<class T>
void DoublyCL<T> :: display()
{
    
    while((first != NULL && last != NULL))
    {
        struct node<T> * temp = first;
        do
        {
            cout << temp->data <<" ";
            temp = temp->next;
            
        }while(temp != first); 

        break;
    }
}

template<class T>
int DoublyCL<T> :: CountNode()
{
    return count;
}

template<class T>
void DoublyCL<T> :: insertatpos(T no, int ipos)
{
    
    if(ipos < 1 ||  ipos > count + 1)
    {
        cout<<"invalid postion\n";
        return;
    }

    if(ipos == 1)
    {
        insertfirst(no);
    }
    else if(ipos == count + 1)
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

        for(i = 1; i < ipos - 1 ; i++)
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
void DoublyCL<T> :: deleteatpos(int ipos)
{
    if(ipos < 1 || ipos > count+ 1)
    {
        cout<<"invalid postion\n";

    }

    if(ipos == 1)
    {
        deletefirst();
    }
    else if (ipos == count)
    {
        deletelast();
    }
    else 
    {
        struct node<T> * targernode = NULL;
        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        targernode = temp->next;
        temp->next = temp->next->next;
        delete targernode;
        temp->next->prev = temp;

    }
}

int main()
{
    DoublyCL<int> iobj;
    DoublyCL<float> fobj;
    DoublyCL<double> dobj;
    DoublyCL<char> cobj;
 
    
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
    
    cout<<"\nLinkedList of Floats : "<<"\n";
    fobj.display();

    dobj.insertfirst(101.999);
    dobj.insertfirst(51.999);
    dobj.insertfirst(21.999);
    dobj.insertfirst(11.999);
    
    cout<<"\nLinkedList of Doubles : "<<"\n";
    iobj.display();

    cobj.insertfirst('D');
    cobj.insertfirst('C');
    cobj.insertfirst('B');
    cobj.insertfirst('A');
    
    cout<<"\nLinkedList of Characters : "<<"\n";
    cobj.display();
 
    return 0;
}

