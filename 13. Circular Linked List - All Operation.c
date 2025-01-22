// 13. Write a program to create a Circular Linked List and show all types of insertion and deletion operations on it. 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

int counter(Node* p) {
    Node* r = p;
    int count = 0;

    if (p != NULL) {
        do {
            count++;
            p = p->next;
        } while (p != r);
    }
    return count;
}

void insert_nth_pos(Node** p, int num, int pos) {
    Node *q, *r;
    int i;

    if (counter(*p) + 1 < pos) {
        printf("Invalid position\n");
        return;
    }

    q = (Node*)malloc(sizeof(Node));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    q->data = num;

    if (pos == 1) {
        if (*p == NULL) {
            q->next = q;
            *p = q;
        } else {
            r = *p;
            while (r->next != *p) {
                r = r->next;
            }
            q->next = *p;
            r->next = q;
            *p = q;
        }
    } else {
        r = *p;
        for (i = 0; i < pos - 2; i++) {
            r = r->next;
        }
        q->next = r->next;
        r->next = q;
    }
}

void delete_nth(Node** p, int pos) {
    Node *r = *p, *t;
    int i;
    if (counter(*p) < pos) {
        printf("Invalid position\n");
        return;
    } else if (pos == 1) {
        if (r->next == r) {
            free(r);
            *p = NULL;
        } else {
            while (r->next != *p) {
                r = r->next;
            }
            r->next = (*p)->next;
            free(*p);
            *p = r->next;
        }
    } else {
        for (i = 0; i < pos - 2; i++) {
            r = r->next;
        }
        t = r->next;
        r->next = t->next;
        free(t);
    }
}

void display(Node* p) {
    Node* r;

    if (p == NULL) {
        printf("Null list\n");
    } else {
        r = p;
        while (p->next != r) {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("%d\n", p->data);
    }
}

int main() {
    Node* head = NULL;
    int choice, num, pos;
    char ch = 'Y';

    while (1) {
        printf("Enter 1 to insert a node at the nth position\n");
        printf("Enter 2 to delete the node at nth position\n");
        printf("Enter 3 to display the circular linked list\n");
        printf("Enter 4 to exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &num);
                printf("Enter the position to insert the node: ");
                scanf("%d", &pos);
                insert_nth_pos(&head, num, pos);
                break;
            case 2:
                printf("Enter the position to delete the node: ");
                scanf("%d", &pos);
                delete_nth(&head, pos);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exited\n");
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }
    return 0;
}
