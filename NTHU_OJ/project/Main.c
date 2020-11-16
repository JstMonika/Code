#include "function.h"
#include <string.h>

int main()
{
    Set *set = create_set();

    char cmd[11];
    while (scanf("%10s", cmd) != EOF)
    {
        if (strcmp(cmd, "insert") == 0)
        {
            int data;
            scanf("%d", &data);
            insert(set, data);
        }
        else if (strcmp(cmd, "erase") == 0)
        {
            int data;
            scanf("%d", &data);
            Node *tmp = erase(set, data);
            if (tmp != NULL)
                free(tmp);
        }
        else if (strcmp(cmd, "check") == 0)
        {
            int data;
            scanf("%d", &data);
            if (check(set, data))
                printf("true\n");
            else
                printf("false\n");
                
            fflush(stdout);
        }
        else if (strcmp(cmd, "print") == 0)
        {
            traversal_set(set);
        }
    }

    return 0;
}