// M.Hamza Shahzad
// 20i-0796
// Question 2

#include <iostream>
using namespace std;


class node
{
public:
    int data;
    node *next;
    node()
    {
        data = 0;
        next = NULL;
    }
};

class CircularLinkedlist
{
public:
    node *tail;
    node *head;
    CircularLinkedlist()
    {
        tail = NULL;
        head = NULL;
    }
    void initialize(int d)
    {
        node *newnode = new node;
        tail = newnode;
        tail->next = newnode;
        tail->data = d;
    }
    void add_begin(int d)
    {
        node *newnode = new node;
        newnode->data = d;
        newnode->next = tail->next;

        tail->next = newnode;
    }

    void add_last(int d)
    {
        node *newnode = new node;
        newnode->data = d;
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }

    void add_at(int pos, int d)
    {
        node *newnode = new node;
        newnode->data = d;
        node *p = tail->next;

        while (pos > 1)
        {
            p = p->next;
            pos--;
        }

        newnode->next = p->next;
        p->next = newnode;
        if (p == tail)
        {
            tail = newnode;
        }
    }

    void delet_first()
    {
        node *p = tail->next;
        tail->next = p->next;
        p->next = NULL;
        delete p;
    }

    void delete_last()
    {
        node *p = tail->next;
        node *temp = tail;

        while (p->next != tail)
        {
            p = p->next;
        }

        p->next = tail->next;
        tail->next = NULL;
        tail = p;
        delete temp;
    }

    void delete_any(int pos)
    {
        node *p = tail->next;
        node *prev = p;

        if (pos == 1)
        {
            tail->next = p->next;
            p->next = NULL;
            delete p;
        }
        else
        {
            while (pos > 1)
            {
                prev = p;
                p = p->next;
                pos--;
            }
            prev->next = p->next;
            p->next = NULL;

            if (p == tail)
            {
                tail = prev;
            }
        }
    }

    void print()
    {
        node *temp = tail->next;

        do
        {
            cout << temp->data << "  ";
            temp = temp->next;
        } while (temp != tail->next);
    }

    void find_mid()
    {
        node*p=tail->next;
        int value=0;
        int count=0;

        do
        {
            count++;
            p=p->next;
            
        } while (p!=tail->next);

        int mid=count/2;
        p=tail->next;
        while(mid>1)
        {
            p=p->next;
            mid--;
        }
       value=p->data;

       cout<<"\n\nThe value of the middle node is "<<value;


        
    }
};
int main()
{
    CircularLinkedlist l1;
    l1.initialize(10);

  
    l1.add_begin(5);
   

   
    l1.add_last(20);
    l1.add_last(25);
    l1.add_last(15);
   
    l1.add_at(2, 16);
    l1.print();

    l1.find_mid();

   

     
}