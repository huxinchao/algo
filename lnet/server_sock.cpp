#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <fcntl.h>
#include <string>
#include "msock.h"
#include "msql.h"

const int PORT = 8888;
const int LISTEN_NUM = 2;

using std::cout;
using std::endl;

int server_fd = -1;
int client_fd = -1;

struct sockaddr_in server_addr;
struct sockaddr_in client_addr;

socklen_t addrlen = sizeof(struct sockaddr);


int try_recvconnect() {
    if(-1 == server_fd) {
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if(server_fd < 0) {
            cout << "[socket] create server-fd failed" << endl;
            return -1;
        } else {
            cout << "[socket] create server-fd successed" << endl;
        }

        if(true == m_connect("root","123456")) {
            cout << "[mysql] connect sql-server successed" << endl;
        } else {
            cout << "[mysql] connect sql-server failed" << endl;
            return -1;
        }

        bzero(&server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        server_addr.sin_port = htons(PORT);

        int err = bind(server_fd, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr));
        if(err < 0) {
            cout << "[socket] bind port failed" << endl;
            return -1;
        } else {
            cout << "[socket] bind port successed" << endl;
        }

        err = listen(server_fd, LISTEN_NUM);
        if(err < 0) {
            cout << "[socket] Listen Error" << endl;
            return -1;
        } else {
            cout << "[socket] Listening..." << endl;
        }



        client_fd = accept(server_fd, reinterpret_cast<struct sockaddr*>(&client_addr), &addrlen);
        int sflags = fcntl(client_fd, F_GETFL, 0);
        sflags |= sflags | O_NONBLOCK;
        fcntl(client_fd, F_SETFL, sflags);
        return client_fd;
    } else {
        client_fd = accept(server_fd, reinterpret_cast<struct sockaddr*>(&client_addr), &addrlen);
        int sflags = fcntl(client_fd, F_GETFL, 0);
        sflags |= sflags | O_NONBLOCK;
        fcntl(client_fd, F_SETFL, sflags);
        return client_fd;
    }

}

msg_st recvfromclient(int fd) {

    msg_st retst;

    int timestamp = time(0);
    while(1) {
        int size = recv(fd, reinterpret_cast<msg_st*>(&retst), 1024, 0);
        

    }
}