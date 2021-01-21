#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
void display(int);

class linkedlist
{
    private:
        int ll_size;
        struct struct_node
        {
            struct struct_node* next;
            int data;
        };
        typedef struct_node* node_ptr;
        node_ptr head, cursor;

    public:
        linkedlist() {
            head = nullptr;
            cursor = nullptr;
            ll_size = 0;
        }

        bool empty() {
            return !ll_size;
        }

        void insert (int idata) {
            node_ptr new_node = new struct_node();
            new_node->data = idata;
            new_node->next = nullptr;
            
            //if at head
            if(empty()) {
                head = new_node;
                cursor = new_node;
            }

            else {
                cursor->next = new_node;
                cursor = cursor->next;
            }

            ll_size++;
        }

        void return_list(void(*ptr_fun)(int odata)) {
            if(empty())
                return;
            else {
                auto temp = head;
                while(temp) {
                    (*ptr_fun)(temp->data);
                    temp = temp->next;
                }
            }
        }

        void delete_node (node_ptr previous, node_ptr del_node) {
            //if del_node == head
            
            //if del_node == tail
            if (del_node->next == nullptr) {
                del_node = nullptr;
                previous->next = nullptr;
            }
            
            //other
            else {
                previous->next = del_node->next;
                del_node = nullptr;
            }
        }

        void remove_duplicates() {
            auto temp = head;
    
            while (temp && temp->next) {
                while (temp->data == temp->next->data) {
                    delete_node(temp, temp->next);
                    if(!temp->next)
                        break;
                }
            temp = temp->next;
            }
        }
};

void display(int dis_data) {
    std::cout << dis_data << std::endl;
}

int main() {
    linkedlist lst;

    for (int i = 1; i <= 5; i++)
    {
        lst.insert(i);
        lst.insert(i);
    }
    
    
    std::cout << "\nBefore : " << std::endl;
    lst.return_list(display);

    lst.remove_duplicates();
    std::cout << "\nAfter : " << std::endl;
    lst.return_list(display);

    return 0;
}