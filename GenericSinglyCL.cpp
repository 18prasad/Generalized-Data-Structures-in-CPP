#include<iostream>
using namespace std;

template<class T>
 struct node
{
    T data;
    struct node *next;
    
};


template<class T>
class SinglyC
{
    private:
        struct node<T> * first;
        struct node<T>* last;
        int Count;
    public:
        SinglyC();
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
SinglyC<T> :: SinglyC()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

template<class T>
void SinglyC<T> :: insertfirst(T no)
{
    struct node<T>* newn = NULL;

    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    
    if(first == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
       
        first = newn;
        last->next = first;
    }
    Count++;
}

template<class T>
void SinglyC<T> :: insertlast(T no)
{
    struct node<T>* newn = NULL;

    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
   

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
        newn->next = first;
        
    }
    Count++;

}

template<class T>
void SinglyC<T> :: deletefirst()
{
    if(first == NULL)
    {
        return;
    }
    else if( first == last)
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
    }
    Count--;
}

template<class T>
void SinglyC<T> :: deletelast()
{
    if(first == NULL)
    {
        return;
    }
    else if ( first == last)
    {
        delete first;
        first = NULL;
        last =  NULL;
    }
    else 
    {
        struct node<T> * temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;

    }
    Count--;
}

template<class T>
void SinglyC<T> :: display()
{
    struct node<T> * temp = first;

   if((first != NULL) && (last != NULL))
   {

        do
        {
            cout<< temp->data<<" ";
            temp = temp->next;

        }while(temp != last->next);
   }
}

template<class T>
int SinglyC<T> :: CountNode()
{
    return Count;
}

template<class T>
void SinglyC<T> :: insertatpos(T no, int ipos)
{
    if((ipos < 1 ) || ipos > Count + 1)
    {
        cout<<"invalid postion";
        return;
    }

    if(ipos == 1)
    {
        insertfirst(no);
    }
    else if(ipos == Count )
    {
        insertlast(no);
    }
    else
    {
        int i = 0;
        struct node<T> * newn = NULL;
        struct node<T> * temp = first;
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        
        for(i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    
    }
    Count++;
}

template<class T>
void SinglyC<T> :: deleteatpos(int ipos)
{
    if((ipos < 1 ) || ipos > Count)
    {
        cout<<"invalid postion";
        return;
    }

    if(ipos == 1)
    {
        deletefirst();
    }
    else if(ipos == Count)
    {
        deletelast();
    }
    else
    {
        struct node<T> * targetnode = NULL;
        struct node<T> * temp = first;
        int i = 1;
        
        for(i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;

        }
        
        targetnode = temp->next;
        temp->next = temp->next->next;
        delete targetnode;

    }
    Count --;
}

int main()
{
     SinglyC<int> iobj;
     SinglyC<float> fobj;
     SinglyC<double> dobj;
     SinglyC<char> cobj;

     iobj.insertlast(11);
     iobj.insertlast(21);
     iobj.insertlast(51);
     iobj.insertlast(101);

     cout<<"LinkedList of Integers : "<<"\n";
     iobj.display();

     fobj.insertlast(11.99);
     fobj.insertlast(21.99);
     fobj.insertlast(51.99);
     fobj.insertlast(101.99);

     cout<<"\nLinkedList of Floats : "<<"\n";
     fobj.display();

     dobj.insertlast(11.999);
     dobj.insertlast(21.999);
     dobj.insertlast(51.999);
     dobj.insertlast(101.999);

     cout<<"\nLinkedList of Doubles : "<<"\n";
     dobj.display();

     cobj.insertlast('A');
     cobj.insertlast('B');
     cobj.insertlast('C');
     cobj.insertlast('D');

     cout<<"\nLinkedList of Characters : "<<"\n";
     cobj.display();
     


    return 0;
}