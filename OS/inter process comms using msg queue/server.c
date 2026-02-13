#include "common.h"

int main() {
    int msgid;
    struct mesgq message;

    // 3. Create message queue
    msgid = msgget(KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    printf("Enter text, ^D to quit:\n");

    // 5. Loop until Ctrl+D (EOF)
    while (fgets(message.text, MAX, stdin) != NULL) {
        // b. Delete newline character
        message.text[strcspn(message.text, "\n")] = 0;

        // c. Send message to Client (Type 1)
        message.type = 1;
        msgsnd(msgid, &message, sizeof(message.text), 0);

        // d. Retrieve response from Client (Type 2)
        if (msgrcv(msgid, &message, sizeof(message.text), 2, 0) == -1) {
            break;
        }

        // e. Display text contents
        printf("From Client: \"%s\"\n", message.text);
        printf("Enter text, ^D to quit:\n");
    }

    // 6. Remove message queue
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
