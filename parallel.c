// habe es komplet neu gemacht
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

char* arguments[] = {"ls", "df", "ps", "pwd"};
int status;

int main(int argc, char const *argv[])
{
  int count = 0;
  while(count != 4)
  {
    char* current[] = {arguments[count], arguments[4]};
    int pid = fork();
    if (pid == 0)
    {
      execvp(current[0], current);

      printf("ERROR\n");
    }
    else
    {
        waitpid(-1, &status, 0);
    }
    count++;
  }

  printf("Done\n");

  return 0;
}
