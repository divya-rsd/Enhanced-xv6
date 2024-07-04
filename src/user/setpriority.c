#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: setpriority pid priority\n");
        exit(0);
    }
    int pid = atoi(argv[1]);
    int priority = atoi(argv[2]);
    int old_priority = set_priority(pid, priority);

    if (old_priority == -1)
    {
        printf("Error: Process with PID %d not found.\n", pid);
    }
    else
    {
        printf("Changed priority of process with PID %d from %d to %d.\n", pid, old_priority, priority);
    }
    exit(0);
}
