#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(long n) {
    if (n <= 1) return false;
    for (long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int pfd[2]; // Array for pipe descriptors
    pid_t pid;
    long fib[25];

    // 3. Create pipe
    if (pipe(pfd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    // 4. Create child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        /* CHILD PROCESS */
        close(pfd[0]); // Close unused read end

        printf("Child process generates Fibonacci series\n");
        fib[0] = 0;
        fib[1] = 1;
        printf("%ld %ld ", fib[0], fib[1]);

        for (int i = 2; i < 25; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
            printf("%ld ", fib[i]);
            if ((i + 1) % 8 == 0) printf("\n"); // Formatting output
        }
        printf("\n");

        // 6. Write array to pipe
        write(pfd[1], fib, sizeof(fib));
        close(pfd[1]); // Close write end
        exit(0);

    } else {
        /* PARENT PROCESS */
        close(pfd[1]); // Close unused write end

        // 7. Wait for child to complete
        wait(NULL);

        // 8. Read from pipe
        read(pfd[0], fib, sizeof(fib));
        close(pfd[0]); // Close read end

        // 9. Inspect and print primes
        printf("Parent prints Fibonacci that are Prime\n");
        for (int i = 0; i < 25; i++) {
            if (is_prime(fib[i])) {
                printf("%ld ", fib[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
