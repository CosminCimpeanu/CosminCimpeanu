#include <stdio.h>

struct node
{
    int element;
    struct node* urm;
};


void init(struct node* head)
{
    head = NULL;
}


struct node* push(struct node* head, int element)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        exit(0);
    }
    tmp->element = element;
    tmp->urm = head;
    head = tmp;
    return head;
}

struct node* pop(struct node* head, int* element)
{
    struct node* tmp = head;
    *element = head->element;
    head = head->urm;
    free(tmp);
    return head;
}

int empty(struct node* head)
{
    if (head == NULL) return 1;
    else return 0;
}


void display(struct node* head)
{
    struct node* current;
    current = head;
    if (current != NULL)
    {
        do
        {
            printf("%d ", current->element);
            current = current->urm;
        } while (current != NULL);
        printf("\n");
    }
    else
    {
        printf("Stiva este goala\n");
    }

}



int main()
{
    struct node* head = NULL;
  
    int* element = (int*)malloc(sizeof(int));
    int* size = (int*)malloc(sizeof(int));
    size = 7;
    int* i = (int*)malloc(sizeof(int));
    int* opt = (int*)malloc(sizeof(int));

    init(head);

    for (*i = 0; *i < 7; (*i)++)
    {
        printf("Introdu numarul %d  ", *i + 1);
        scanf("%d", &element);
        head = push(head, element);
    }
    do
    {
        printf("1.Afisare\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("0.Exit\n");
        printf("Opt=");
        scanf("%d", opt);
        switch (*opt)
        {
        case 1:
            display(head);
            break;
        case 2:
            head = pop(head, &element);
            break;
        case 3:
            printf("%d \n", *head);
            break;
        case 0:
            exit(0);
            break;
        default :
            printf("ERR\n");
            break;
        }
    } while (*opt !=0);
   
    return 0;
}