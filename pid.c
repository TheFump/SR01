#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<errno.h>
#include<sys/wait.h>

int main(){

pid_t pid_pere = getpid();
pid_t pid_fils1 = fork();
pid_t pid;
int status;


if(pid_fils1 == -1){
printf("Erreur : impossible de créer un fork(), errno : %d \n", errno);
return 1;
}
if(pid_fils1 == 0){
printf("ici le Fils 1 : mon PID est : %d, celui de mon père est : %d\n" ,getpid(), pid_pere);
exit(1);
}
else{

pid_t pid_fils2 = fork();

if(pid_fils2 == -1){
printf("Erreur : impossible de créer un fork(), errno : %d \n", errno);
return 1;
}
if(pid_fils2 == 0){
printf("ici le Fils 2 : mon PID est : %d, celui de mon père est : %d\n" ,getpid(), pid_pere);
exit(2);
}
else{
printf("ici le pere : mon PID est : %d, celui de mon fils 1  est : %d, , celui de mon fils 2  est : %d\n" ,getpid(), pid_fils1, pid_fils2);

if(((pid = waitpid(pid_fils1, &status, 0)) > 0) && (WIFEXITED(status))) {
printf("Le processus père termine le procssus fils numero %d\n", status>>8);
}
if(((pid = waitpid(pid_fils2, &status, 0)) > 0) && (WIFEXITED(status))){
printf("Le processus père termine le procssus fils numero %d\n", status>>8);
}

}
}
return 0;}

