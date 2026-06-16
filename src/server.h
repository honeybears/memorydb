#include <sys/types.h>
#include <pthread.h>

enum ServerStatus {
    WAITING,
    RUNNING,
    SHUTTING_DOWN,
    ERROR
};

struct MemoryDBServer {
    pid_t pid;
    pthread_t main_thread_id;
    int port;
    int listen_fd;
    enum ServerStatus status;
    //Todo: Event Loop and Key Value 
};

extern struct MemoryDBServer server;

void initServer(int port);

void startServer();

void closeServer();