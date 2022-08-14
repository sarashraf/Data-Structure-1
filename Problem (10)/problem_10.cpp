#include <iostream>
#include<algorithm>

using namespace std;

template<class T>
//creating the node of the doubly linked list
struct node
{
    T data;
    node<T>*next;
    node<T>*prev;

};
template <class T>
//class mylist
class mylist
{
private:
    node<T>*head;
    node<T>*tail;
    node<T> * dummyNode=new node<T>;
public :
    friend class Iterator;
    //declaration of the size of list(cnt)
    int cnt=0;

//the default constructor of the class
    mylist()
    {
        head= dummyNode;
        tail=dummyNode;
    }

    // the parametrized constructor of the class which takes the data of the node and the intial size of the list as parameters
    mylist(T value , int intial_size)
    {
        head= dummyNode;
        tail=dummyNode;
        for (int i=0;i<intial_size;i++)
        {
            node<T>*new_node;
            new_node=new node<T>;
            if (head==dummyNode)
            {
                new_node->data = value;
                new_node->next=head;
                head->prev=new_node;
                head=new_node;
            }
            else
            {
                node<T>*last;
                last=head;
                while(last->next!= dummyNode)
                {
                    last=last->next;
                }
                new_node->data=value;
                last->next=new_node;
                new_node->prev=last;
                new_node->next=dummyNode;
                dummyNode->prev=new_node;
            }
            //increasing the size of list by one each time a node is inserted
            cnt++;
        }
    }
    //function which returns the size of list
    int sizeOfList()
    {

        return cnt;
    }

    node<T>* gethead()
    {
        return head;
    }


//the inner class iterator
    class Iterator
    {
    private:
        node<T>*it;
    public:

//the default constructor of class iterator
        Iterator()
        {
            it=nullptr;
        }
        //the parametrized constructor of class iterator
        Iterator (const Iterator &ptr)
        {
            it=ptr.it;
        }
//function which equates two pointers
        void setIterator(node<T>* h)
        {
            it=h;
        }
        //function which return the pointer of the iterator
        node<T> *getIterator()
        {
            return it;
        }
        //check if the two iterators points to the same node
        bool operator ==(const Iterator & obj)
        {
            if(it==obj.it)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //moves the iterator to the next node
        void operator ++ (int)
        {
               /* if(it == head)
               {
                   throw"you have reached the end of the list.";
               }*/
            it=it->next;
        }
//moves the iterator to the previous node
        void operator --(int)
        {
            /*
            if(it==head)

            {
                cout<<"yess"<<endl;
                throw "Sorry you have reached the beginning of the list";
            }
            */

            it=it->prev;
        }
        //returns the data in the node which the iterator points at
        T & operator *()
        {
            return it->data;
        }

        //check if the two iterators are not pointing to the same node
        bool operator !=(const Iterator &obj)
        {
            if(it==obj.it)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
//end of the class Itertor
    };

//return an iterator pointing to the begin of the list
    Iterator beginlist()
    {

        Iterator iter;
        iter.setIterator(head);
        return iter;
    }

    //return an iterator pointing to the end of the list
    Iterator endlist()
    {
        Iterator itr;
        itr.setIterator(tail);
        return itr;
    }

    //function which inserts a node to a certain  position which is passed as parameter
    void insertNode(T val,Iterator &p)
    {

        node<T>*new_node;
        new_node=new node<T>;
        new_node->data=val;
        // in case the position is at the beginning of the list
        if(p==beginlist())
        {
            head->prev=new_node;
            new_node->next=head;
            head=new_node;
        }
            //otherwise
        else
        {
            new_node->prev=p.getIterator()->prev;
            p.getIterator()->prev->next=new_node;
            new_node->next=p.getIterator();
            p.getIterator()->prev=new_node;
        }
        node<T>* temp;
        temp=p.getIterator()->prev;
        p.setIterator(temp);
        cnt++;
    }

    // function which erases a node at the position given(which is passed as a parameter to the function)
    Iterator eraseNodee(Iterator &position)
    {
        if(position==beginlist())
        {
            head=head->next;
            delete head->prev;
            position.setIterator(head);
            cnt--;
            return position;
        }
        else
        {
            if(position==endlist())
            {
                throw "End of list. you can not erase eny nodes!";
            }
            node<T>* temp;
            temp=position.getIterator()->next;
            Iterator x;
            x=position;
            position.getIterator()->prev->next=position.getIterator()->next;
            position.getIterator()->next->prev=position.getIterator()->prev;
            delete x.getIterator();
            position.setIterator(temp);
            cnt--;
            return position;
        }
    }
    friend class Iterator;

    //  a function which clears the list
    void clearNode()
    {
        Iterator it;
        it=beginlist();
        int x=sizeOfList();
        for(int i =0;i<x;i++)
        {
            eraseNodee(it);
        }
    }

    //overloading operator = which copy the list into another one
    mylist<T> &operator = ( mylist<T> &anotherList)
    {
        clearNode();
        Iterator iter=anotherList.beginlist();
        Iterator itt=beginlist();
        while (iter !=anotherList.endlist())
        {

            insertNode(*iter,itt);

            itt.setIterator(itt.getIterator()->next);
            iter++;

        }
        return anotherList;
    }

    ~mylist()
    {
        clearNode();

    }

};

int main()
{
    //list to test paramitrized constructor,beginList,insertNode,++,eraseNode

    mylist<int> list(8,4);         //inserting four nodes with value 8 in list
    mylist<int>::Iterator it = list.beginlist();      //iterator pointing to the beginning of the list
    it++;
    list.insertNode(2,it);                   //inserting node with value 2 in the second node
    it++;
    it++;
    it++;
    it++;                //the iterator pointing to a node after the last one
    cout<<endl<<"trying to delete a node after the last node of the list which doesn't exist: "<<endl;
    try
    {
        list.eraseNodee(it);
    }
    catch (const char * e)
    {
        cout<<"error! "<<e<<endl;           //catch the error as there is no node to be deleted
    }
    mylist<int>::Iterator iter = list.beginlist();   //pointer to the beginning of list to print the values inside the list
    cout<<"elements of list 1: "<<endl;
    for(int i=0;i<list.sizeOfList();i++)
    {

        cout<<*iter<<endl;
        iter++;
    }
    cout<<"---------------------------------------------------------"<<endl;

    mylist<int> list2(5,2);  //inserting two nodes with value 5 in list2

    mylist<int>::Iterator itr = list2.beginlist();
    list2.insertNode(3,itr); //insert node with value 3 at the beginning of the list2
    list2.insertNode(1,itr);//insert node with value 1 at the beginning of the list2
    list2.insertNode(2,itr);//insert node with value 2 at the beginning of the list2

    mylist<int>::Iterator it2 = list2.beginlist(); // it2 pointing to the beginning of list2
    cout<<"elements of list 2 after inserting node of values (2,1,3) :"<<endl;
    for(int i=0;i<list2.sizeOfList();i++)   // printing list2 after inserting new nodes
    {

        cout<<*it2<<endl;
        it2++;
    }
    cout<<"---------------------------------------------------------"<<endl;

    list2.eraseNodee(itr); // erase the first node in list2
    itr++;
    itr++;
    list2.eraseNodee(itr); //erase the third element in list2

     mylist<int>::Iterator it1 = list2.beginlist();//pointer to the beginning of list to print the values inside the list
    cout<<"elements of list 2 after erasing the first and fourth node: "<<endl;
      for(int i=0;i<list2.sizeOfList();i++) //printing list 2 after erasing node from it
      {

          cout<<*it1<<endl;
          it1++;
      }
    cout<<"---------------------------------------------------------"<<endl;


    list2=list; //copying list in list2
    mylist<int>::Iterator iter1 = list2.beginlist();
    cout<<"elements of list 2 after copying list 1 in list 2: "<<endl;
    for(int i=0;i<list2.sizeOfList();i++) //printing elements of list2 after copying the values of list in it
    {
        cout<<*iter1<<endl;
        iter1++;
    }
    cout<<"---------------------------------------------------------"<<endl;



    mylist<int>::Iterator it3 = list.endlist(); //it3 is an iterator pointing to the end of list
    it--;
    it--;
    list.eraseNodee(it);

    mylist<int>::Iterator it4 = list.beginlist();
    cout<<"elements of list 1 after erasing an element from it : "<<endl;
    for(int i=0;i<list.sizeOfList();i++) //printing elements of list after erasing a node
    {
        cout<<*it4<<endl;
        it4++;
    }
    cout<<"---------------------------------------------------------"<<endl;

    mylist<int>::Iterator it5= list2.beginlist();
    cout<<"elements of list 2 which is not affected by the changes in list 1: "<<endl;
    for(int i=0;i<list2.sizeOfList();i++) //printing elements of list2 after the changes done in list
    {
        cout<<*it5<<endl;
        it5++;                      //list 2 is not affected ny changes in list
    }
    cout<<"---------------------------------------------------------"<<endl;

    return 0;
}
