#ifndef LOOP_H
#define LOOP_H

#define AE_NONE     0
#define AE_READABLE 1
#define AE_WRITABLE 2

typedef struct Loop Loop;

typedef void LoopFileHandler(Loop *loop, int fd, void *clientData, int mask);

typedef enum {RUNNING, STOPPED} LoopStatus;

typedef struct LoopFileEvent {
    int mask;
    LoopFileHandler *rFileHandler;
    LoopFileHandler *wFileHandler;
    void *clientData;
} LoopFileEvent;


typedef struct LoopFiredEvent {
    int fd;
    int mask;
} LoopFiredEvent;

struct Loop {
    int setSize;
    LoopFileEvent *events;
    LoopFiredEvent *firedEvents;
    LoopStatus status;
    void *apiData;
};

Loop *loopCreate(int setSize);
void loopFree(Loop *loop);
void loopStop(Loop *loop);

int loopCreateFileEvent(Loop *loop, int fd, int mask, LoopFileHandler *handler, void *clientData);
void loopDeleteFileEvent(Loop *loop, int fd, int mask);
int loopGetFileEvents(Loop *loop, int fd);

int loopProcessEvents(Loop *loop, int flags);
void loopMain(Loop *loop);

#endif