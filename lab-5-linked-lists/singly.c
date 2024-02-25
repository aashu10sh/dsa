#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct Node * next;
} Node ;

void traverse(Node * head);
void insertAtEnd(Node * head, Node * new);
void insertAtBeginning(Node * head, Node * new);
int count(Node * head);
int search(Node * head, int data);

int main(void){
    Node * head = (Node *) malloc(sizeof(Node));
    Node * first = (Node * ) malloc(sizeof(Node)); 
    Node * second = (Node *) malloc(sizeof(Node));
    Node * third = (Node *) malloc(sizeof(Node));
    Node * fourth = (Node *) malloc(sizeof(Node));
    Node * fifth = (Node *) malloc(sizeof(Node));

    
    head->data = NULL;
    first->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;
    fifth->data = 5;


    head->next = first;
    first->next = second;
    second ->next = third;
    third->next = NULL;
    
    traverse(head);
    insertAtEnd(head, fourth);
    traverse(head);
    insertAtBeginning(head, fifth);
    traverse(head);
    count(head);
    search(head,25);


    free(first);
    free(second);
    free(third);
    free(fourth);
    free(fifth);
}


void traverse(Node * head){
    Node * temp = head;
    while(temp != NULL){
        if (temp->data == 0 ){
            temp = temp->next;
            continue;
        }
        printf("The Data is : %d\n",temp->data);
        temp = temp->next;
    }
    puts("------");
}

void insertAtBeginning(Node * head, Node * new){
    Node * temp = head ;
    Node * original = head->next;
    head->next = new;
    new->next = original;
}

void insertAtEnd(Node * head, Node * new){
    Node * temp = head;
    while(temp != NULL){
        if (temp->next == NULL){
            temp->next = new;
            new->next = NULL;
        }
        temp = temp->next;
    }
    return new;
}

int count(Node * head){
    int count = 0;
    Node * temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    count = count - 1;
    printf("The Count is %d\n", count);
    return count; // compensation for head
}

void deleteAtBeginning(Node * head){
    
}

int search(Node * head, int data){
    Node * temp = head;
    int index = -1;
    while(temp!=NULL){
        if(temp->data == data){
            printf("Data Found at Index %d\n", index);
            return index;
        }
        temp= temp->next;
        index++;
    }
    puts("Data Not Found");
    return index;
}