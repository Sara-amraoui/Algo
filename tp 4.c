#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node *next;;
} Node;

Node* createEmptyList() {
    return NULL;
}

int isEmpty(Node *head) {
    return head == NULL;
}

Node* insertAtBeginning(Node *head, Product newProd) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = newProd;
    
    if (head==NULL) {
        newNode->next = newNode;
       return newNode;
    } 
    else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    
    return head;
}

Node* insertAtEnd(Node *head, Product newProd) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;
    
    if (head==NULL) {
        newNode->next = newNode;
       return newNode
 
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    
    return head;
}

void displayProducts(Node *head) {
    if (isEmpty(head)) {
        printf("The list is empty.\n");
        return;
    }
    
    Node *temp = head;
    
  
    do {
        printf("ID: %d, Name: %s, Price: %d\n", 
               current->Prod.ID, 
               current->Prod.Name, 
               current->Prod.Price);
        current = current->next;
    } while (temp!= head);
    
    

int main() {

    
    Node *head = createEmptyList();
    printf("1. Created empty list.\n");
    
 
 
    
    Product p1 = {101, "Laptop", 1500};
    Product p2 = {102, "Mouse", 25};
    Product p3 = {103, "Keyboard", 75};
    Product p4 = {104, "Monitor", 300};
    
 
    head = insertAtBeginning(head, p1);
    
    head = insertAtEnd(head, p2);
  
    head = insertAtBeginning(head, p3);

    
    head = insertAtEnd(head, p4);
   
    
    
    displaylist(head);
    

    displayProducts(newList);
    
   
    return 0;
}
