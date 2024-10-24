#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main (int argc, char * argv[])
{
    printf("My pid: %d My parent pid %d\n", getpid(), getppid());
    return 0;
}