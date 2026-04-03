#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};
void sum();

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Create two linked lists
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the first linked list
    insertEnd(&list1, 1);
    insertEnd(&list1, 2);
    insertEnd(&list1, 3);

    // Insert elements into the second linked list
    insertEnd(&list2, 4);
    insertEnd(&list2, 5);
    insertEnd(&list2, 6);

    // Display the linked lists
    printf("Linked List 1: ");
    displayList(list1);

    printf("Linked List 2: ");
    displayList(list2);

    // Free allocated memory
    struct Node* temp;
    while (list1 != NULL) {
        temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2 != NULL) {
        temp = list2;
        list2 = list2->next;
        free(temp);
    }

    return 0;
}
void sum(){
    struct Node *ptr;
    int count=0;
    ptr=list1;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        count++;
        
    }

}
class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(struct Node* num1, struct Node* num2) {
       struct Node *ptr,*cpt;
       ptr=num1;//ptr pointing at head of num1
       int count=0
       while(ptr->next!=NULL){
           ptr=ptr->link;
           count++;
           
       }
       cpt=num2;//cpt pointing head of num1 
       int count1=0
       while(cpt-next!=NULL){
           cpt=cpt->link;
           count1++;
           
       }
       if count1>count2{
           x=count2-count1
           ptr=num1;
           
       }
       
        // code here
    }
};