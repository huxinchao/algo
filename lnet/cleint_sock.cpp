#include "msock.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <iostream>
#include <netinet/tcp.h>
#include "fcntl.h"
const int PORT = 8888;

using std::cout;
using std::endl;
static int server_fd = -1;


bool try_connect() {
    
    struct sockaddr_in server_addr;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) {
        cout << "[socket] create socket failed" << endl;
        return false;
    }
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    int err = connect(server_fd, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(struct sockaddr));

    int sflags = fcntl(server_fd, F_GETFL, 0);
    sflags |= sflags | O_NONBLOCK;
    fcntl(server_fd, F_SETFL, sflags);

    if(err < 0) {
        cout << "[socket] connect failed" << endl;
        server_fd = -1;
        close(server_fd);
        return false;
    } else {
        cout << "[socket] connect successed : " << server_fd << endl;
    }
    return true;
}

bool sendtoserver(int type, const char* buf, int len) {
    if(-1 == server_fd) {
        cout << "[upload-socket] socket don't connect" << endl;
        return false;
    } else {
        msg_st mgt;
        memset(&mgt, 0, sizeof(msg_st));
        mgt.type = type;
        memcpy(mgt.msg, buf, len);
        mgt.len = len;
        
        struct tcp_info info;
        int i_len = sizeof(info);
        ssize_t size = send(server_fd, reinterpret_cast<char*>(&mgt), sizeof(mgt),0);
        if(size <= 0) {
            close(server_fd);
            server_fd = -1;
            return false;
        }
        long long timestamp = time(0);
        while(true) {
            msg_st mgt;
            memset(&mgt, 0, sizeof(msg_st));
            size = recv(server_fd, reinterpret_cast<char*>(&mgt), sizeof(mgt), 0);
            if(time(0) - timestamp > 5) {
                close(server_fd);
                server_fd = -1;
                return false;
            }
            if(size <= 0) {
                close(server_fd);
                server_fd = -1;
                return false;
            } else {
                break;
            }
        }
    }
    return true;
}