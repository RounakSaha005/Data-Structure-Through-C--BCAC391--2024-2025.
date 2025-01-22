//14. Write a program to create a Doubly Linked List and show all types of insertion and deletion operation on it. 
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node {
    struct node* prev;
    int data;
    struct node* next;
} Dnode;

void dinsert_nth(Dnode **p, int n, int pos) {
    Dnode *q, *r = *p;
    int i;
    q = (Dnode*) malloc(sizeof(Dnode));
    q->data = n;
    if (pos == 1) {
        q->prev = NULL;
        q->next = *p;
        if (*p != NULL) {
            (*p)->prev = q;
        }
        *p = q;
    } else {
        for (i = 0; i < pos - 2 && r != NULL; i++) {
            r = r->next;
        }
        if (r != NULL) {
            q->prev = r;
            q->next = r->next;
            if (r->next != NULL)
                r->next->prev = q;
            r->next = q;
        } else {
            printf("Invalid position!\n");
            free(q);
        }
    }
}

void ddelete_nth(Dnode **p, int pos) {
    Dnode *r = *p;
    int i;
    if (*p == NULL) {
        printf("Null List! Deletion Not Possible\n");
    } else if (pos == 1) {
        if (r->next != NULL)
            r->next->prev = NULL;
        *p = r->next;
        free(r);
    } else {
        for (i = 0; i < pos - 1 && r != NULL; i++) {
            r = r->next;
        }
        if (r != NULL) {
            if (r->prev != NULL)
                r->prev->next = r->next;
            if (r->next != NULL)
                r->next->prev = r->prev;
            free(r);
        } else {
            printf("Invalid position!\n");
        }
    }
}

void ddisplay(Dnode *p) {
    Dnode *r = p;
    if (p == NULL) {
        printf("Null List\n");
    } else {
        while (r != NULL) {
            printf("%d\t", r->data);
            r = r->next;
        }
        printf("\n");
    }
}

void dinsert_end(Dnode **p, int n) {
    Dnode *q, *r = *p;
    q = (Dnode*) malloc(sizeof(Dnode));
    q->data = n;
    q->next = NULL;
    if (*p == NULL) {
        q->prev = NULL;
        *p = q;
    } else {
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = q;
        q->prev = r;
    }
}

int main() {
    Dnode *head = NULL;
    int num, loc, choice;
    char opt;
    printf("PROGRAM TO IMPLEMENT DOUBLE LINKED LIST\n");
    printf("=======================================\n");
    printf("1. Create/Appending The List\n");
    printf("2. Insert Node At Nth Position\n");
    printf("3. Delete Nth Node\n");
    printf("4. Display The List\n");
    printf("5. Exit\n");
    do {
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                do {
                    printf("Enter The Data : ");
                    scanf("%d", &num);
                    dinsert_end(&head, num);
                    printf("Enter More Data (Y/N)? : ");
                    fflush(stdin);
                    opt = getchar();
                } while (toupper(opt) != 'N');
                break;
            case 2:
                printf("\nEnter The Node Number Before Which New Node Will Be Inserted : ");
                scanf("%d", &loc);
                printf("\nEnter The Data : ");
                scanf("%d", &num);
                dinsert_nth(&head, num, loc);
                break;
            case 3:
                printf("\nEnter The Node Number You Want To Delete : ");
                scanf("%d", &loc);
                ddelete_nth(&head, loc);
                break;
            case 4:
                ddisplay(head);
                break;
            case 5:
                printf("\nQuitting...\n");
                exit(0);
            default:
                printf("Invalid Choice. Please Enter Correct Choice !\n");
        }
    } while (1);
    return 0;
}
