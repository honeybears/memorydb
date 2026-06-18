#include "server.h"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

MemoryDBServer server;

void initServer(int port) {
    server.pid = getpid();
    server.main_thread_id = pthread_self();
    server.port = port;
    server.status = WAITING;

    printf("Server initialized on port %d with PID %d\n", server.port, server.pid);
}

void startServer() {
    server.status = RUNNING;
    // TODO: Implement the main server loop to accept connections and handle requests
    printf("Server is running on port %d\n", server.port);
}

void closeServer() {
    server.status = SHUTTING_DOWN;
    // TODO: Signal the main thread to stop accepting new connections and clean up resources
    printf("Server is shutting down...\n");
}