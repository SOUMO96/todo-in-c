#include <stdio.h>
#include <string.h>
#define MAX_TASK 1000
#define MAX_LIMIT 100

struct todo
{
    char task[MAX_TASK];
};

void add_task(struct todo todos[], int *count);
void previous_list(struct todo todos[], int count);

int main()
{
    struct todo todos[MAX_LIMIT];
    int count = 0;
    int choice;
    while (1)
    {
        printf("\nWELCOME\n");
        printf(" 1)ENTER A TASK \n");
        printf(" 2)GET THE PREVIOUS LIST\n");
        printf(" 3)EXIT!\n");
        printf("CHOOSE :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_task(todos, &count);
            break;
        case 2:
            previous_list(todos, count);
            break;
        case 3:
            return 0;
        default:
            printf("INVALID INPUT!");
            break;
        }
    }
    return 0;
}
void add_task(struct todo todos[], int *count)
{
    if (*count >= MAX_LIMIT)
    {
        printf("CANNOT STORE");
    }
    printf("ENTER THE TASK :");
    getchar();
    fgets(todos[*count].task, MAX_TASK, stdin);
    todos[*count].task[strcspn(todos[*count].task, "\n")] = 0;

    printf("TASK ADDED SUCCESFULLY!\n");

    char another;
    printf("DO YOU WANT TO STORE ANOTHER TASK (Y/N): ");
    scanf("%c", &another);
    if (another == 'Y')
    {
        (*count)++;
        add_task(todos, count);
    }
    else
    {
        (*count)++;
    }
}
void previous_list(struct todo todos[], int count)
{

    if (count == 0)
    {
        printf("No tasks in the list.\n");
        return;
    }
    printf("Previous tasks:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, todos[i].task);
    }
}
