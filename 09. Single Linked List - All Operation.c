//9. Write a program to create a Single Linked List and show all types of insertion and deletion operations on it.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void insert_nth(Node **p, int pos, int n) {
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = n;
    if (*p == NULL || pos == 1) {
        q->next = *p;
        *p = q;
    } else {
        Node *r = *p;
        for (int i = 0; i < pos - 2 && r->next != NULL; i++) {
            r = r->next;
        }
        q->next = r->next;
        r->next = q;
    }
}

void delete_nth(Node **p, int pos) {
    if (*p == NULL) {
        printf("Null List! Deletion Not Possible...");
        return;
    }
    Node *r = *p;
    if (pos == 1) {
        *p = r->next;
        free(r);
        return;
    }
    for (int i = 0; i < pos - 2 && r->next != NULL; i++) {
        r = r->next;
    }
    Node *q = r->next;
    r->next = q->next;
    free(q);
}

void display(Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
        if (p != NULL) printf("-> ");
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int num, loc, choice;
    char opt;

    printf("PROGRAM TO IMPLEMENT SINGLE LINKED LIST\n");
    printf("=======================================\n");
    do {
        printf("\n1. Create/Appending The List");
        printf("\n2. Insert Node At Nth Position");
        printf("\n3. Delete Nth Node");
        printf("\n4. Displaying The List");
        printf("\n5. Exit");

        printf("\n\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                do {
                    printf("Enter The Data : ");
                    scanf("%d", &num);
                    insert_nth(&head, counter(head) + 1, num);
                    printf("Enter More Data (Y/N)? : ");
                    while (getchar() != '\n'); // Clear input buffer
                    opt = getchar();
                } while (toupper(opt) != 'N');
                break;
            case 2:
                printf("\nEnter The Node Number Before Which New Node Will Be Inserted : ");
                scanf("%d", &loc);
                printf("\nEnter The Data : ");
                scanf("%d", &num);
                insert_nth(&head, loc, num);
                break;
            case 3:
                printf("\nEnter The Position Which Will Be Deleted : ");
                scanf("%d", &loc);
                delete_nth(&head, loc);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("\nQuitting...\n");
                exit(0);
            default:
                printf("Invalid Choice. Please Enter Correct Choice");
        }
    } while (1);

    return 0;
}
