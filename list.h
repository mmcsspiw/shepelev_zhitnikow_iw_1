#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template<typename T>
class List
{
private:
    struct Node;
public:
    class Iterator{
    public:
        Iterator(Node* node):iNode(node){}

        bool operator==(const Iterator& other) const{
            if(this == &other){
                return true;
            }
            return iNode == other.iNode;
        }

        bool operator!=(const Iterator& other) const{
            return  !operator==(other);
        }

        T operator*() const{
            if(iNode){
                return iNode->data;
            }
            return T();
        }

        void operator++(){
            if(iNode){
                iNode = iNode->next;
            }
        }

        void operator--(){
            if(iNode){
                iNode = iNode->prev;
            }
        }

        T getData() {
            if(!iNode) {
                throw "Index is out of bounds";
            }
            return iNode->data;
        }
        Node* getNode() {
            return iNode;
        }
    private:
        Node* iNode;
    };
public:
    List():head(NULL){}

    ~List(){
        while(head) {
            remove();
        }
    }

    List(const List& t){
        for(Iterator it = t.begin(); it != t.end(); ++it){
            append(it.getData());
        }
    }

    void append(const T& t){
    if(searchElement(t) == NULL){
        Node* node = new Node(t);
        node->next = head;
    if(head){
        head->prev = node;
    }
        head = node;
    }
    }

    void remove(){
        if(head) {
            Node* newHead = head->next;
            if(newHead) {newHead -> prev = NULL;}
            delete head;
            head = newHead;
        }
    }

    void removeElement(const T& t){
        if(!isEmpty()) {
            Iterator it = searchElement(t);
            if(it != NULL){

                if(size() == 1){
                    head = nullptr;
                    delete it.getNode();
                }else if(!(it.getNode()->next)){
                    it.getNode()->prev = nullptr;
                    delete it.getNode();
                }else if(!(it.getNode()->prev)){
                    head = it.getNode()->next;
                    delete it.getNode();
                }else{
                    it.getNode()->prev->next = it.getNode()->next;
                    delete it.getNode();
                }
            }
        }
    }

    bool isEmpty(){
        return !head;
    }

    Iterator searchElement(const T& t){
        if(!isEmpty()) {
            int s = 0;
            Iterator it = begin();
            while(it != end()){
                if(it.getData() == t){
                    return it;
                }
                ++s;
                ++it;
            }
        }
        return end();
    }

    T getElementByIndex(int index){
        if(index >= size()){
            throw "Index is out of bounds";
        }
        Iterator it = begin();
        for(int s = 0; s < index; ++s) {
           ++it;
        }
        return it.getData();
    }

    List getHead() const{
        return head;
    }

    Iterator end() const{
        return Iterator(NULL);
    }

    Iterator begin() const{
        return Iterator(head);
    }

    int size() const{
        int s = 0;
        for(Iterator it = begin(); it != end(); ++it) {
            ++s;
        }
        return s;
    }

    List& operator|=(const T& t){
        append(t);
        return *this;
    }

    List& operator/=(const T& t){
        removeElement(t);
        return *this;
    }

    void print(ostream& os){
        for(Iterator it = begin(); it != end(); ++it){
            if(it!=NULL) {os << it.getData() << endl;}
        }
        os << endl;
    }

    friend std::istream& operator>>(std::istream& is, List<T>& l){
        T t;
        is >> t;
        l.append(t);
        return is;
    }

    friend List operator&&(const List& l1, const List& l2){
        List resl;
        for(Iterator it1 = l1.begin(); it1 != l1.end(); ++it1){
            for(Iterator it2 = l2.begin(); it2 != l2.end(); ++it2){
                if(it1.getData() == it2.getData()){
                    resl.append(it1.getData());
                }
            }
        }
        //List Res = resl.copy();
        //cout << Res << endl;
        return resl;
    }

    friend List operator||(const List& l1, const List& l2){
        List resl;
        for(Iterator it = l1.begin(); it != l1.end(); ++it){
            resl.append(it.getData());
        }
        for(Iterator it = l2.begin(); it != l2.end(); ++it){
            resl.append(it.getData());
        }
        return resl;
    }

    bool operator==(List<T>& l){
       if(size() != l.size()){
           cout << "1!!!" <<endl;
           return false;
       }

       for(Iterator it = begin(); it != end(); ++it){
           if(l.searchElement(it.getData())==NULL){
               cout << "2-010-" <<endl;
               return false;
           }
       }
       cout << "3!--!" <<endl;
       return true;
    }

    bool operator!=(List<T>& l){
        return !(*this == l);
    }
    List copy(){
       List res;
       for(Iterator it = begin(); it != end(); ++it){
            res.append(it.getData());
       }
       return res;
    }
    T operator[](int index)
    {
        return getElementByIndex(index);
    }

    List operator*()
    {
        return getHead();
    }

private:
    struct Node{
        T data;

        Node *prev;

        Node *next;

        Node() : prev(nullptr), next(nullptr){}

        Node(const T& t) : data(t), next(nullptr), prev(nullptr){}
    };

    Node* head;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, List<T>& l){
    l.print(os);
    return os;
}

#endif // LIST_H
