#include <iostream>

template <typename T>
class list{

    struct listNode{
        T val;
        listNode *next;
        listNode(const T& _val): val(_val) , next(nullptr){};

        ~listNode(){
            delete next;
        }
    };

    listNode *head;
    listNode *tail;


public:

    list(): head(nullptr),tail(nullptr){

    }

    list(const T& _val) {
        head = new listNode(_val);
        tail = head;
    }

    void append(const T& _val){
        listNode* newNode = new listNode(_val);
        if(!head){
            head = tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }

    void traverse() const{
        listNode * tmp = head;
        while(tmp){
            std::cout << tmp->val << " ";
            tmp = tmp -> next;
        }
        std::cout << std::endl;
    }


    ~list(){
        delete head;
    }
};

int main() {
    list<int> myList(5);
    myList.append(5);
    myList.append(4);
    myList.traverse();
    myList.append(3);
    myList.traverse();

    list<int> mysecondList;
    mysecondList.append(1);
    mysecondList.append(2);
    mysecondList.append(5);
    mysecondList.traverse();
    return 0;
}