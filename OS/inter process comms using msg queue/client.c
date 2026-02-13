#include "common.h"

int main() {
    int msgid;
    struct mesgq message;

    // 3. Open message queue
    msgid = msgget(KEY, 0666);
    if (msgid == -1) {
        perror("msgget failed (is the server running?)");
        exit(1);
    }

    printf("Client ready:\n");

    // 4. Do while message queue exists
    while (1) {
        // a. Retrieve message from Server (Type 1)
        if (msgrcv(msgid, &message, sizeof(message.text), 1, 0) == -1) {
            break; // Exit if queue is removed by server
        }

        // b. Display text
        printf("From Server: \"%s\"\n", message.text);

        // c. Get message from user
        if (fgets(message.text, MAX, stdin) == NULL) break;

        // d. Delete newline
        message.text[strcspn(message.text, "\n")] = 0;

        // e. Send to Server (Type 2)
        message.type = 2;
        msgsnd(msgid, &message, sizeof(message.text), 0);
    }

    printf("Server Disconnected\n");
    return 0;
}
