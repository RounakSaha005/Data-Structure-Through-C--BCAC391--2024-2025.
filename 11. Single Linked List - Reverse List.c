//11. Write a program to create a Single Linked List and reverse it.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void insert_end(Node **p, int num) {
    Node *q, *r;

    q = (Node*)malloc(sizeof(Node));
    q->data = num;

    if (*p == NULL) {
        q->next = NULL;
        *p = q;
    } else {
        r = *p;

        while (r->next != NULL) {
            r = r->next;
        }
        q->next = NULL;
        r->next = q;
    }
}

void display(Node *p) {
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

Node* reverse(Node *head) {
    Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    Node *head = NULL;
    int num, choice;
    char ch = 'Y';

    while (1) {
        printf("\nEnter 1 to insert new node\n");
        printf("Enter 2 to display the list\n");
        printf("Enter 3 to reverse the list\n");
        printf("Enter 4 to exit\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            while (toupper(ch) == 'Y') {
                printf("Enter the number\n");
                scanf("%d", &num);
                insert_end(&head, num);

                fflush(stdin);

                printf("CONTINUE(Y/N): ");
                scanf(" %c", &ch);
            }
            break;

        case 2:
            display(head);
            break;

        case 3:
            head = reverse(head);
            display(head);
            break;

        case 4:
            printf("Exited\n");
            exit(0);
            break;

        default:
            printf("Invalid Input\n");
        }
    }
}
