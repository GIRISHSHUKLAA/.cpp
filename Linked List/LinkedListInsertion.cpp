// C++ program for insertion in a single linked
// list at a specified position
#include <iostream>
using namespace std;

// A linked list Node
struct Node
{
    int data;
    struct Node *next;
};

// Size of linked list
int size = 0;

// function to create and return a Node
Node *getNode(int data)
{
    // allocating space
    Node *newNode = new Node();

    // inserting the required data
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a Node at required position
void insertPos(Node **current, int pos, int data,int size)
{
    // This condition to check whether the
    // position given is valid or not.
    if (pos < 1 || pos > size + 1)
        cout << "Invalid position!" << endl;
    else
    {

        // Keep looping until the pos is zero
        while (pos--)
        {

            if (pos == 0)
            {

                // adding Node at required position
                Node *temp = getNode(data);

                // Making the new Node to point to
                // the old Node at the same position
                temp->next = *current;

                // Changing the pointer of the Node previous
                // to the old Node to point to the new Node
                *current = temp;
            }
            else
                // Assign double pointer variable to point to the
                // pointer pointing to the address of next Node
                current = &(*current)->next;
        }
        size++;
    }
}

// This function prints contents
// of the linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        cout << " " << head->data;
        head = head->next;
    }
    cout << endl;
}

// Driver Code
int main()
{
    // Creating the list 3->5->8->10
    Node *head = NULL;
    head = getNode(3);
    head->next = getNode(5);
    head->next->next = getNode(8);
    head->next->next->next = getNode(10);

    int size = 4;

    cout << "Linked list before insertion: ";
    printList(head);

    int data = 12, pos = 3;
    insertPos(&head, pos, data,size);
    cout << "Linked list after insertion of 12 at position 3: ";
    printList(head);

    // front of the linked list
    data = 1, pos = 1;
    insertPos(&head, pos, data,size);
    cout << "Linked list after insertion of 1 at position 1: ";
    printList(head);

    // insertion at end of the linked list
    data = 15, pos = 7;
    insertPos(&head, pos, data,size);
    cout << "Linked list after insertion of 15 at position 7: ";
    printList(head);

    return 0;
}













/* 
// Understand insert at any position


node** means a double pointer to a single pointer who points to a node object. You need node** pointer to make the head of a linked list at caller scope to point to something else (like a new node when you add a node ahead in the linked list or to point to NULL when you delete the only element present in the linked list)
void insert(node** head, int value) 
{ 
    node* new_node = new node 
    node *last = *head; 
    new_node->data  = value; 
  
    new_node->next = NULL; 
    if (*head == NULL) 
    { 
       *head = new_node; 
       return; 
    } 
  
    while (last->next != NULL) 
        last = last->next; 
  
    last->next = new_node; 
    return; 
} 
So, when the above function gets called and if you had used node* instead of node** for head in function parameter, then changes made for pointing by head pointer inside function scope would not get reflected in the actual head pointer variable present at caller scope. This will happen because when you write node* head inside function argument, the address value will be passed from the calling function which will be stored inside node* head. So any future changes within function like making node* head to point to something else will be made on node* head present at function scope instead of actual node* head present at caller scope.

Hence, when you want to change the actual head pointer present at caller scope to point something else, you must pass the address of actual head pointer to a double pointer function argument. So, like in above code, within if block, you can see by using *head you can make actual head pointer present at caller scope to point NULL.

The above concept can be similarly applied to a delete function for a linked list.

The bottom line is “Changes made for pointing at a single pointer function parameter won’t get reflected in caller scope. You can manipulate the objects or values pointed by node* from inside function but you cannot manipulate the pointer present at caller scope to point something else by just using node*. Therefore, you use node** for manipulating pointers at caller scope and node* for manipulating objects at called scope”.
*/
