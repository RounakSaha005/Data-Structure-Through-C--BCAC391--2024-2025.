//12. Write a program to create a Single Linked List and eliminate duplicate elements from it.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void insert_end(Node **head, int num) {
    Node *newNode, *current;

    newNode = (Node*) malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void removeDuplicates(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    Node* prev = NULL;
    Node* temp = NULL;

    while (current != NULL && current->next != NULL) {
        prev = current;

        while (prev->next != NULL) {
            if (current->data == prev->next->data) {
                temp = prev->next;
                prev->next = prev->next->next;
                free(temp);
            } else {
                prev = prev->next;
            }
        }
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    int num, choice;
    char ch;

    while (1) {
        printf("\nEnter 1 to insert new node\n");
        printf("Enter 2 to display the list\n");
        printf("Enter 3 to remove duplicate\n");
        printf("Enter 4 to exit\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("Enter the number\n");
                    scanf("%d", &num);
                    insert_end(&head, num);

                    printf("CONTINUE(Y/N): ");
                    while (getchar() != '\n');
                    scanf("%c", &ch);
                } while (toupper(ch) == 'Y');
                break;

            case 2:
                display(head);
                break;

            case 3:
                removeDuplicates(head);
                break;

            case 4:
                printf("Exited\n");
                exit(0);

            default:
                printf("Invalid Input\n");
        }
    }
}
