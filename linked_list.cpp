#include <iostream>
class Node{
    public:
        int data;
        Node* next;
};
class LinkedList{
    public:
        LinkedList() : head(nullptr) {}
        
        void push(int ele, int pos){
            Node* temp = new Node();
            temp->data = ele;
            if(pos == 1){
                temp->next = head;
                head = temp;
                return;
            }
            Node* temp2 = head;
            for (int i = 0; i < pos - 2; i++) {
                temp2 = temp2->next;
            }
            temp->next = temp2->next;
            temp2->next = temp;
        }
        void del(int n){
            Node* temp = head;
            if(n == 1){
                head = temp->next;
                delete temp;
                return;
            }
            for (int i = 0; i < n-2; i++) {
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        void display(){
            Node* temp = head;
            std::cout <<"Linked list : ";
            while(temp != nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
            std::cout<<std::endl;
        }
        void reverse(){
            Node *prv,*cur,*next;
            cur = head;
            prv = nullptr;
            while(cur != nullptr){
                next = cur->next;
                cur->next = prv;
                prv = cur;
                cur = next;
            }
            head = prv;
        }
    private:
        Node* head;
};
int main(void){
    int n;
    bool run = true;
    LinkedList mylist;
    std::cout<<" linked list implemention :\n"
            " 1. insert element in list\n"
            " 2. del element by index\n"
            " 3.reverse all element\n"
            " 4. display all element\n"
            " 5. stop\n";
            while(run){
                std::cout<<"\nenter number: ";
                std::cin>>n;
                switch (n){
                    case 1:
                        int ele,pos,t;
                        std::cout<<"\nhow many input:";
                        std::cin>>t;
                        for(int i=0; i<t; i++){
                            std::cout<<"\nenter element and index:";
                            std::cin>>ele>>pos;
                            mylist.push(ele,pos);
                        }
                        break;
                    case 2:
                        int n;
                        std::cout<<"\nenter index:";
                        std::cin>>n;
                        mylist.del(n);
                        break;
                    case 3:
                        mylist.reverse();
                        break;
                    case 5:
                        run = false;
                        std::cout<<"\t.....EXIT.....";
                        break;
                    case 4:
                        mylist.display();
                        break;
                    default:
                        std::cout<<"\n error with your input\n";
                }
            }
    return 0;
}
