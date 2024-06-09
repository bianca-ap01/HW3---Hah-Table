//
// Created by bianca on 08/06/24.
//

#ifndef HW3_HASH_TABLE_LINKEDLIST_H
#define HW3_HASH_TABLE_LINKEDLIST_H
template <class T>
class LinkedList{
private:
    struct ListNode{
        T val;
        ListNode* next;
        ListNode(): next(nullptr){};
        ListNode(T value): next(nullptr), val(value){};
    };
    int sz;
    ListNode* head;
public:
    LinkedList(): head(nullptr), sz(0){};

    int size(){return sz;}

    int end(){return sz;}

    int find(T value){ // returns index of the first ocurrencee of value
        auto temp = head;
        for(int i = 0; i < sz; i++){
            if(temp->val == value) return i;
            temp = temp->next;
        }
        return -1; // value wasnt found on list
    }


//    inserts

    void insert(T value){
        auto node = new ListNode(value);
        if(head == nullptr)
            head = node;
        else{
            auto temp = head;
            while(temp->next) temp = temp->next;

            temp->next = node;
        }
        sz++;
    }

    void insert(int index, T value){
        if(index >= sz or index < 0){throw('Out of Bounds!');}
        auto node = new ListNode(value);
        if(head == nullptr){head = node;}
        else {
            auto temp = head;
            for (int i = 0; i <= index; i++) {
                temp = temp->next;
            }

            node->next = temp->next->next;
            temp->next = node;
        }
        sz++;
    }

    void add_front(T value){
        auto node = new ListNode(value);
        if(head == nullptr) throw ('List is empty!');
        node->next = head;
        head = node;
        sz++;
    }

//    quitar objetos

    void remove(int index){
        if(index >= sz or index < 0) throw('Out of bounds!');
        if(head == nullptr) throw('Empty List!');
        else{
            auto temp = head;
            for(int i = 0; i <= index; i++){
                temp = temp->next;
            }

            auto aux = temp;
            temp = temp->next;
            delete aux;
        }
        sz--;
    }

    void remove_values(T value){
        if(head == nullptr) throw('Empty List!');
        auto temp = head;
        while(temp){
            if(temp->val == value){
                auto aux = temp;
                temp = temp->next;
                delete aux;
                sz--;
            }

            if(temp == nullptr) return;
            temp = temp->next;
        }
    }

    void remove_value(T value){
        if(head == nullptr) throw('Empty List!');
        auto temp = head; ListNode* prev = nullptr;
        while(temp){
            if(temp->val == value){
                if(prev == nullptr) head = temp->next;
                else prev->next = temp->next;
                delete temp;
                sz--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    T pop_front(){
        if(head == nullptr) throw('List is empty!');
        auto temp = head;
        T value = temp->val;
        head = head->next;
        delete temp;
        sz--;
        return head->val;
    }

    T pop_back(){
        if(head == nullptr) throw('List is empty');
        auto temp = head, prev = head;
        while(temp->next){
            prev = temp;
            temp = temp->next;
        }
        T value = temp->val;
        delete temp;
        prev->next = nullptr;
        sz--;
        return value;
    }

    void clear(){
        auto aux = head;
        while(aux){
            aux = head;
            head = head->next;
            delete head;
        }
        delete aux;
        head = nullptr;
        sz = 0;
    }

//    operator[]
    T operator[](int index){
        if(head == nullptr) throw ('List is empty!');
        if(index >= sz or index < 0) throw ('Out of bounds!');
        auto temp = head;
        for(int i = 0; i <= index; i++){
            temp = temp->next;
        }
        return temp->val;
    }

//    reverse list
    void reverse(){
        if(head == nullptr or head->next == nullptr) return;
        ListNode* prev = nullptr, curr = head, next = nullptr;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    ~LinkedList(){
        clear();
        delete head;
    }
};

#endif //HW3_HASH_TABLE_LINKEDLIST_H
