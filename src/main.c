#include "server.h"

int main(void) {
    initServer(6123);
    startServer();
    closeServer();
    return 0;
}