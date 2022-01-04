#include <iostream>

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

using std::cout;
using std::endl;

int main() {
	fd_set rd;
	timeval tv;
	int err;
	int fd = 1;

	FD_ZERO(&rd);
	FD_SET(fd, &rd);

	tv.tv_sec = 1;
	tv.tv_usec = 0;

	while(1) {
		err = select(fd + 1, NULL, &rd, NULL, &tv);
		if(-1 == err) {
			perror("select()");
		} else if(err) {
			cout << "data is available" << endl;
			if(FD_ISSET(fd, &rd)) {
				cout << "something in" << endl;
			}
		} else {
			cout << "no data within 1 sec" << endl;
			if(FD_ISSET(fd, &rd)) {
				cout << "something in" << endl;
			} else {
				cout << "nothing in" << endl;
			}
		}
	}
		
	return 0;
}
