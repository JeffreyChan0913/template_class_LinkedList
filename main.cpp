#include <iostream>
#define np nullptr

template<class T>
struct Node
{
        T data;
        Node<T>* next = np;
};

template<class T>
class Linklist
{
        private:
                Node<T>* head = np;
                T listSize = 0;
        public:
                void add(const T x);
                void display();
                void rm(const T x);
                void reverse();
                void find(const T x);
                void getSize();
                void setSize();
                void addBefore(const T beforeThis, const T x);
                void addAfter(const T afterThis, const T x);
                void addFront(const T x);
                ~Linklist();
};

template<typename T>
Linklist<T>::~Linklist()
{
        std::cout << "Destorying head " << std::endl;
        delete head;
}

template<typename T>
void Linklist<T>::addFront(const T x)
{
        if(head != np)
        {
                Node<T>* newNode = new Node<T>;
                newNode -> data = x;
                newNode -> next = head -> next;
                head = newNode;
        }
        else
        {
                std::cout << "Empty list" << std::endl;
        }
}

template<typename T>
void Linklist<T>::addBefore(const T beforeThis, const T x)
{
        Node<T>* tmp = head;
        if(tmp != np)
        {
                while(tmp != np)
                {
                        if(tmp -> next -> data == beforeThis)
                        {
                                Node<T>* newNode = new Node<T>;
                                newNode -> data = x;
                                newNode -> next = tmp -> next;
                                tmp -> next = newNode;
                                break;
                        }
                        tmp = tmp -> next;
                }
        }
        else
        {
                std::cout << "Empty list" << std::endl;
        }
}

template<typename T>
void Linklist<T>::addAfter(const T afterThis, const T x)
{
        Node<T>* tmp = head;
        if(tmp != np)
        {
                while(tmp != np)
                {
                        if(tmp -> data == afterThis)
                        {
                                Node<T>* newNode = new Node<T>;
                                newNode -> data = x;
                                newNode -> next = tmp -> next;
                                tmp -> next = newNode;
                                break;
                        }
                        tmp = tmp -> next;
                }
        }
        else
        {
                std::cout << "Empty list" << std::endl;
        }
}
template<typename T>
void Linklist<T>::find(const T x)
{
        Node<T>* tmp = head;
        if(tmp != np)
        {
                while(tmp != np)
                {
                        if(tmp -> data == x)
                        {
                                std::cout << x << " in on the list." << std::endl;
                                break;
                        }
                        tmp = tmp -> next;
                }
        }
        else
        {
                std::cout << "Empty list" << std::endl;
        }
}

template<typename T>
void Linklist<T>::display()
{
        int i = 0;
        Node<T>* tmp = head;
        if(head != np)
        {
                while(tmp != np)
                {
                        std::cout << i << ": " << tmp->data << std::endl;
                        tmp = tmp -> next;
                        i++;
                }
        }
        else
        {
                std::cout << "Empty list" << std::endl;
        }
}

template<typename T>
void Linklist<T>::setSize()
{
        listSize += 1;
}

template<typename T>
void Linklist<T>::getSize()
{
        std::cout << "The size of the linked list is: " << listSize << std::endl;
}

template<typename T> 
void Linklist<T>::reverse()
{
        Node<T>* cur = head;
        Node<T>* lastNode = cur;
        if(cur != np)
        {
                std::cout << "Reversing the linked list" << std::endl;
                Node<T>* prev = np;
                Node<T>* nextOne = head->next;

                while(nextOne != np)
                {
                        prev = cur;
                        cur = nextOne;
                        nextOne = cur -> next;
                        cur -> next = prev;
                }
                head = cur;
                lastNode -> next = np;
        }
        else
        {
                std::cout << "Empty List" << std::endl;
        }
}

template<typename T>
void Linklist<T>::add(const T x)
{
        setSize();
        Node<T>* tmp = head; 
        Node<T>* newnode = new Node<T>;
        newnode -> data = x;
        if(tmp != nullptr)
        {
                while(tmp -> next != np)
                {
                        tmp = tmp -> next;
                }
                tmp->next = newnode;
        }
        else
        {
                std::cout << "Empty list, setting head -> data = " << x << std::endl;
                head = newnode; 
        }
}

template<typename T> 
void Linklist<T>::rm(const T x)
{
        if(head != np)
        {
                std::cout << "Removing " << x << std::endl;
                Node<T>* tmp = head;
                Node<T>* rTmp = np;
                while(tmp -> next != np)
                {
                        if(tmp -> next -> data == x)
                        {
                                rTmp = tmp -> next;
                                tmp -> next = tmp -> next -> next;
                                delete rTmp;
                                std::cout << "Removed" << std::endl;
                                break;
                        }
                        tmp = tmp -> next; 
                }
        }
        else
        {
                std::cout << "Empty list, nothing has been removed" << std::endl;
        }
}

int main()
{
        Linklist<int> obj;
        obj.add(10);
        obj.add(50);
        obj.add(100);
        obj.add(150);
        obj.display();
        obj.addBefore(100, 75);
        obj.display();
        obj.addAfter(100, 125);
        obj.display();
        obj.addFront(5);
        obj.display();
        obj.~Linklist();
        obj.display();
        return 0;

}
