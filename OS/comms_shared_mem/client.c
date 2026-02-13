#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    int shmid;
    key_t key = 2013;
    char *shm, *s;
    size_t shmsize = 27;

    // 3. Obtain access to the shared memory segment
    shmid = shmget(key, shmsize, 0666);
    if (shmid < 0) {
        printf("Server not started\n");
        exit(1);
    }

    printf("Accessing shared memory id : %d\n", shmid);

    // 4. Attach client process to shared memory
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // 5. Read contents
    printf("Shared memory contents:\n");
    for (s = shm; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // 6. Modify the first character to '*'
    *shm = '*';

    // Detach from memory
    shmdt(shm);

    return 0;
}
