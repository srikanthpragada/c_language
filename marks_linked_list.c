// linked list
#include <stdio.h>

struct node  {
    int marks;
    struct node * next;
};

main()
{
    struct node * root = NULL, *current, *prev;
    int marks, total = 0, count = 0, avg;

    while(1)
    {

        printf("Enter marks [-1 to stop] :");
        scanf("%d", &marks);
        if (marks < 0)
           break;

        // allocate a block
        current = (struct node *) malloc(sizeof(struct node));
        current->next = NULL;
        current->marks = marks;

        total += marks;
        count++;

        if (root == NULL)
            root = current; // set root to first node
        else
            prev->next = current;

        prev = current;
    } // while

    avg = total / count;

    // display marks that are > average

    current = root;
    while(current != NULL)
    {
        if ( current -> marks > avg)
            printf("\n%d", current -> marks);

        current = current-> next;
    }


}
