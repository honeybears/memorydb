#include <sys/types.h>
#include <pthread.h>

typedef enum ServerStatus {
    WAITING,
    RUNNING,
    SHUTTING_DOWN,
    ERROR
} ServerStatus;

typedef struct MemoryDBServer {
    pid_t pid;
    pthread_t main_thread_id;
    int port;
    int listen_fd;
    ServerStatus status;
    //Todo: Event Loop and Key Value 
} MemoryDBServer;

extern MemoryDBServer server;

void initServer(int port);

void startServer();

void closeServer();