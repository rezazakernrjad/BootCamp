
/*Write a function that insert linked list node at any position. The function takes the data of the node and the
node position as inputs.
For example if we have a linked list contains the followingdata nodes: 11 3 10 50 23 5 60
If you asked the function to insert a new node has data equals to 15 at position 3 the linked list should be: 
11 3 10 15 50 23 5 60
*/

#include<iostream>
#include<string>
#include <climits>
using namespace std;

class Node {
    public:
//        Node();
        int elem;
        Node* next;
//        Node(int elem_, Node* next_): elem{elem_}, next{next_}{};
};

int main(){
    Node* head = nullptr;
    Node* node_1 = nullptr;
    Node* node_2 = nullptr;
    Node* node_3 = nullptr;
    head = new Node();
    node_1 = new Node();
    node_2 = new Node();
    node_3 = new Node();
    Node* node_tmp = nullptr;
    node_tmp = new Node();
    head->elem = 1;
    head->next = node_1;
    node_1->elem = 3;
    node_1->next = node_2;
    node_2->elem = 7;
    node_2->next = node_3;
    node_3->elem = 9;
    node_3->next = nullptr;
    int elem_x{0};
    int pos_x{0};;
    cout << "Enter new position for new List: " ;
    cin >> pos_x;
    Node* node_4 = nullptr;
    cout << "Enter element of new List: " ;
    cin >> elem_x;
    node_4 = new Node();
    int pos{0};
    node_4->elem = elem_x;
    for (Node* node = head; node; node = node->next){
        if (pos > pos_x-2){
            node_tmp->next = node->next;
            node->next = node_4;
            node_4->next = node_tmp->next;
            pos = INT_MIN;
            
        }
        pos++;
        cout << "element: " << node->elem << endl;
    }

    return 0;
}
/*
void add_list(Node* anchor, int new_element){
    anchor = new Node{new_element, anchor};
for (Node* node = anchor; node; node = node->next){
        cout << "element_added: " << node->elem << endl;
    }

}

int main(){

   Node* anchor{};
   Node* node_1{};
   Node* node_2{};
   anchor = new Node{7, anchor};
   anchor = new Node{9, anchor};
   anchor = new Node{21, anchor};
    for (Node* node = anchor; node; node = node->next){
    cout << "element: " << node->elem << endl;
    }
    int elem_x{0};
    cout << "Enter new element for new List: " ;
    cin >> elem_x;
    add_list(anchor, elem_x);

    return 0;
}
*/