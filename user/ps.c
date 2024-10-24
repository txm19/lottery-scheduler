#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

enum COLOR {
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    INDIGO,
    VIOLET
};
#include "kernel/pstat.h"

int
main(int argc, char *argv[])
{

  struct pstat p;
  getpinfo(&p);

  // Print header
  printf("NAME\tPID\tSTATUS\t\tCOLOR\tTICKETS\n");

  // Iterate through each process in the pstat struct
  for (int i = 0; i < NPROC; i++) {
    if (p.inuse[i]) {
      // Print process name
      printf("%s\t", p.name[i]);

      // Print process PID
      printf("%d\t", p.pid[i]);

      // Print process state
      switch (p.state[i]) {
        case UNUSED:
          printf("UNUSED\t\t");
          break;
        case USED:
          printf("USED\t\t");
          break;
        case SLEEPING:
          printf("SLEEPING\t");
          break;
        case RUNNABLE:
          printf("RUNNABLE\t");
          break;
        case RUNNING:
          printf("RUNNING\t\t");
          break;
        case ZOMBIE:
          printf("ZOMBIE\t\t");
          break;
      }

      // Print process color
      switch (p.color[i]) {
        case RED:
          printf("RED\t");
          break;
        case ORANGE:
          printf("ORANGE\t");
          break;
        case YELLOW:
          printf("YELLOW\t");
          break;
        case GREEN:
          printf("GREEN\t");
          break;
        case BLUE:
          printf("BLUE\t");
          break;
        case INDIGO:
          printf("INDIGO\t");
          break;
        case VIOLET:
          printf("VIOLET\t");
          break;
      }

      // Print process tickets
      printf("%d\n", p.tickets[i]);
    }
  }

  exit(0);
}
