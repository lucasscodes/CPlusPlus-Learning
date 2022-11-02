#include <iostream>
using namespace std;

struct Node {
    int value;
    struct Node* next;
};

//Declares a Linked List-Class
class LinkedList
{
    private: //Hidden inside the class
        Node *head; //Saves the pointer to the first node
        Node *tail; //Saves the pointer to the next node
    public: //Functions inside are callable from outside of the class
        //Node *head; //Allowed manipulation inside the main method, now private
        
        //Constructor Method:
        //creates needed head/tail-Vars
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        //Insert int at the end of the List
        //O(1) complexity
        void insertNode(int value)
        {
            Node *temp = new Node; //Construct a Node
            temp->value = value;
            temp->next = nullptr;

            if (head == nullptr) //If list empty
            {
                head = temp;
                tail = temp;
            }
            else //Already ints inside
            {	
                tail->next = temp;
                tail = temp;
            }
        }

        //Push a int infront of the whole List/"Stack"
        //O(1) complexity
        void pushNode(int value) {
            Node *new_node = new Node;

            new_node->value = value;
            new_node->next = head;

            if (head == nullptr) { //If there arent any elements set the tail!
                tail = new_node;
            }
            head = new_node;
        }

        //Returns and deletes the last Element
        //O(n) complexity
        int deleteNode() {
            if(head == nullptr) { //If empty list
                throw std::runtime_error("Tried to delete a empty List!");
            }
            int retval = 0;
            if(head->next == nullptr) { //If only one element
                Node *last_node = nullptr;

                last_node = head->next;
                retval = head->value;
                delete head;
                head = last_node;

                return retval;
            }
            Node *node_before = head;
            Node *last_node = head->next;

            //Find Node pointing to the tail
            while (last_node->next != nullptr) {
                node_before = last_node;
                last_node = last_node->next;
            }
            retval = last_node->value;
            delete last_node;
            node_before->next = nullptr; //Is now the last one
            tail = node_before; //Update field
            
            return retval;
        }
        
        //Returns and deletes the first int of the List
        //O(1) complexity
        int popNode() {
            if(head == nullptr) { //If empty List
                throw std::runtime_error("Tried to pop from a empty List!");
            }
            int retval = 0;
            Node *last_node = nullptr;

            last_node = head->next;
            retval = head->value;
            delete head;
            head = last_node;

            return retval;
        }

        //Delete the first node with given value
        //Set silent to false and it will raise errors!
        //Errors: Not found, empty list, empty print
        //O(n) complexity
        void removeByValue(int value, bool silent = true) {
            if(head == nullptr) { //If empty list
                if (silent) { 
                    return;
                }
                else {
                    throw std::runtime_error("Tried to search in empty List!");
                }
            }
            Node *node = head; //Start searching here, will change live!
            if(head->next == nullptr) { //If only one element
                if (head->value == value) {
                    delete node;
                    head = nullptr;
                    tail = nullptr;
                    return;
                }
                else {
                    throw std::runtime_error("Element not in list!");
                }
            }
            if(head->value == value){ //If its the first element
                Node *node = head;
                head = head->next;
                delete node;
                return;
            }
            //Now it must be behind or not inside!
            Node *next_node = head->next;
            //Find Node with given value
            while (next_node->value != value) { //While value not found, go on
                if (next_node->next == nullptr) {
                    if (silent) {
                        return; //Not in list
                    }
                    else {
                        throw std::runtime_error("Element not in list!");
                    }
                }
                node = node->next; 
                next_node = next_node->next;
            }
            //Value found and should be inside of next_node now!
            if (next_node == tail) { //If tail gets cutted, replace it
                tail = node;
            }
            node->next = next_node->next; //Next node cant get accessed now!
            delete next_node;
        }

        //Print the whole list
        //Set silent to false and this will throw error on empty list
        //O(n) complexity
        void printList(bool silent = true) {
            if (head == nullptr) {
                if (!silent) {
                    throw std::runtime_error("Tried to print a empty List!");
                }
                else {
                    return; //Empty list
                }
            }
            Node* current = head;

            while (current != nullptr) {
                std::cout << current->value;
                current = current->next;
            }
        }
};


void testRemovedByValue() {
    //Testscases removedByValue(): empty, single, first, second, last
    LinkedList linkedlist2;
    //linkedlist2.removeByValue(1,false); //EMPTY throws appropriate error

    //SINGLE
    linkedlist2.pushNode(3);
    //linkedlist2.removeByValue(1,false); //Wrong SINGLE throws appropriate error
    linkedlist2.removeByValue(3); //Del SINGLE works!
    //linkedlist2.printList(false); //Raises appropriate emptyList error

    linkedlist2.pushNode(3);
    linkedlist2.pushNode(2);
    linkedlist2.pushNode(1);
    linkedlist2.pushNode(1);
    linkedlist2.pushNode(0);
    linkedlist2.pushNode(0); //Got 001123 now
    linkedlist2.removeByValue(0); //Remove FIRST in LIST
    linkedlist2.printList();
    cout << " <= should be 01123!" << endl;
    //linkedlist2.removeByValue(9,false); //Remove unknown throws appropriate error
    linkedlist2.removeByValue(1); //Remove MIDDLE in LIST
    linkedlist2.printList();
    cout << " <= should be 0123!" << endl;
    linkedlist2.removeByValue(3); //Remove LAST in LIST
    linkedlist2.printList();
    cout << " <= should be 012!" << endl;
    cout << "If everything worked, removeByValue works just fine!" << endl;
}

void testDelPushPop() {
    LinkedList linkedlist;

    //linkedlist.deleteNode(); //Created a runtime error to prevent a segFault
    //linkedlist.popNode(); //Created a runtime error to prevent a segFault
    linkedlist.pushNode(3);
    linkedlist.pushNode(3);
    linkedlist.pushNode(2);
    linkedlist.pushNode(1);
    linkedlist.pushNode(1);
    linkedlist.popNode();
    linkedlist.deleteNode();

    linkedlist.printList(); 
    cout << " <= should be 123!" << endl;
    cout << "If it worked, del+push+pop are working just fine!" << endl;
}

int main() {
    //linkedlist.head = nullptr; //To make this unpossible, set fields private
    testDelPushPop();
    testRemovedByValue();

    return 0;
}