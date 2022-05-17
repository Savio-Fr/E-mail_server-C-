#ifndef INBOX_H
#define INBOX_H

typedef struct inbox {
    int priority; // prioridade
    char msg[100];
} Inbox;

typedef struct list *inboxList;

inboxList *ini_inboxList();

#endif