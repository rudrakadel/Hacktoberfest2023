
#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int x ;
    struct stack *next;
}st;

st *new;
st *new1;
st *ptr1;
st *loc;
st *locp;
st *head = NULL ;
static int element = 0;
void create(st *);
void display(st *);
void pop(st *);
void push(st *);

int main(){
    st *ptr ;
    int choice ;
    char ch = 'y';
    system("cls");
    fflush(stdin);
    ptr = (st *)malloc(sizeof(st));
    head = ptr;
    while(ch == 'y'){
        printf("\n MAIN MENU  \n 1. CREATE STACK  \n 2. VIEW STACK \n 3. PUSH IN STACK \n 4. POP IN STACK \n 5. EXIT \nEnter your choice here =  ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("CREATION OF STACK .......... \n");
            create(head);
            break;
            case 2:
            printf("DISPLAY OF STACK .......... \n");
            display(head);
            break;
            case 3:
            printf("PUSH IN STACK .......... \n");
            push(head);
            break;
            case 4:
            printf("POP FROM STACK .......... \n");
            pop(head);
            break;
            defaul:printf("please enter a valid choice ");
        }
        printf("/n WANT TO CONTINUE ??(y/n) ");
        scanf(" %c",&ch);
    }
}

void create(st *ptr){
    char ch='y';
    printf("enter current node element :- ");
    scanf("%d",&ptr->x);
    ptr->next = NULL ;
    printf("want to continue ?");
    scanf(" %c",&ch);
    if((ch=='y')||(ch=='Y')){
        ptr->next = (st*)malloc(sizeof(st));
        ptr =ptr->next;
        return(create(ptr));
    }
    
}

void display(st *ptr){
    while(ptr != NULL){
        printf("%d->",ptr->x);
        ptr=ptr->next ;
    }
    printf("NULL/n");
}

void push(st *ptr){
    st *new ;
    new = (st*)malloc(sizeof(st));
    while(ptr->next !=  NULL){
        ptr = ptr->next ;
    }
    new->next = ptr->next ;
    ptr->next = new ;
    printf("ENTER THE ELEMENT OF THE NEW NODE ");
    scanf("%d",&new->x);
}

void pop(st *head) {
    if (head == NULL) {
        printf("STACK EMPTY\n");
        return;
    } else if (head->next == NULL) {
        // If there is only one element in the stack
        free(head);
        head = NULL;
    } else {
        st *ptr = head;
        st *ptr1 = head->next;

        while (ptr1->next != NULL) {
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }

        ptr->next = NULL;
        free(ptr1);
    }
}
