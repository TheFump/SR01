#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int status;
void my_system(char *path, char **argv); //execv() sera lancé dans un processus fils afin d'éviter de remplacer le père

int main()
{
    char *argv1[] = {"ls", "-al", NULL};
    my_system("/bin/ls", argv1);
    
    printf("\n");
    
     char *argv2[] = {"sh", "-c", "ls *.c", NULL}; // char *argv2[] = {"ls", "*.c", NULL};
    my_system("/bin/sh", argv2);
    
    return 0;
}


void my_system(char *path, char **argv)
{
    pid_t pid_fils = fork();
    
    if (pid_fils == -1)
    {
	printf("Erreur fork()");
	return;
    }
    else if (pid_fils == 0)
    {
	execv(path, argv);
    }
    else
    {
	if (waitpid(pid_fils, &status, 0) > 0)
	{
	    if (!WIFEXITED(status))
		printf("Erreur execv\n");
	}
    }
}
