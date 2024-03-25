#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Possibilita as chamadas de sistema
#include <signal.h> // Tratamento de sinais
#include <sys/wait.h> // Nos permite usar a função wait, necessária para esperar que o processo filho termine. 

int main() {
    pid_t pid; // Variável para armazenar o ID do processo
    int status; // Variável para armazenar o status de saída do processo filho

    pid = fork(); // Cria uma cópia do processo (cópia exata do processo pai)

    if (pid == 0) {
        // Esse é processo filho. O getpid() retorna o PID do processo atual (filho)
        // e getppid() retorna o PID do processo pai do processo atual (filho).
        printf("Processo filho: \nPID do Processo Filho = %d\nPID do Processo Pai = %d\n", getpid(), getppid());
        exit(0); // Termina o processo filho (sucesso)

    } else if (pid > 0) {
        // Esse é o processo pai. O getpid() retorna o PID do processo atual (pai)
        // e a variável 'pid' já contém o PID do processo filho.
        printf("Processo pai: \nPID do Processo Pai = %d\nPID do Processo Filho = %d\n", getpid(), pid);
        wait(&status); // O processo pai espera que o processo filho termine antes de continuar

    } else {
        // Se ocorrer um erro ao criar o processo filho.
        perror("Ocorreu um erro na criacao do processo filho.");
        return 1; // O processo pai retorna 1 para indicar erro
    }

    return 0; // O processo pai retorna 0 para indicar sucesso
}
