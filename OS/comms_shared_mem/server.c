#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main() {
    int shmid;
    key_t key = 2013;
    char *shm, *s;
    size_t shmsize = 27;

    // 3. Create the shared memory segment
    shmid = shmget(key, shmsize, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // 4. Display shmid
    printf("Shared memory id : %d\n", shmid);

    // 5. Attach process to shared memory
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // 6. Clear contents
    memset(shm, 0, shmsize);

    // 7. Write a-z onto shared memory
    printf("Writing (a-z) onto shared memory\n");
    s = shm;
    for (char c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    // 8. Wait until client modifies the first character to '*'
    while (*shm != '*') {
        sleep(1);
    }

    printf("Client finished reading\n");

    // 9. Detach process
    shmdt(shm);

    // 10. Remove shared memory
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
