//10. Write a program to create a Single Linked List and sort it in ascending order.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void insert_end(Node **p, int num) {
    Node *q, *r;

    q = (Node*) malloc(sizeof(Node));
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

void sortList(Node *p) {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;

    if (p == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = p;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the values
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Node *head = NULL;
    int num, choice;
    char ch;

    while (1) {
        printf("\nEnter 1 to insert new node\n");
        printf("Enter 2 to display the list\n");
        printf("Enter 3 to sort list in ascending order\n");
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
                    getchar(); // To consume the newline character left by scanf
                    ch = getchar();
                } while (toupper(ch) == 'Y');
                break;

            case 2:
                display(head);
                break;

            case 3:
                sortList(head);
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

    return 0;
}
