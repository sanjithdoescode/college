#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define KEY 2013
#define MAX 100

// Structure for message queue
struct mesgq {
    long type;
    char text[MAX];
};
