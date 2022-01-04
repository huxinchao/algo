#include <iostream>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

using namespace std;

int child_events = 0;

void child_sig_handler(int x) {
	child_events++;
	signal(SIGCHLD, child_sig_handler);
}

int main() {
	sigset_t sigmask, orig_sigmask;
	sigemptyset(&sigmask);
	sigaddset(&sigmask, SIGCHLD);

	sigprocmask(SIG_BLOCK, &sigmask, &orig_sigmask);

	signal(SIGCHLD, child_sig_handler);

	fd_set rd;

	FD_ZERO(&rd);
	FD_SET(0, &rd);

	timespec tv;
	tv.tv_sec = 3;
	tv.tv_nsec = 0;
	char buf[16];

	while(1) {

		int r = pselect(1, &rd, NULL, NULL, &tv, NULL);
		cout << "RES:" << r << endl;
		if(r > 0) {
			int l = read(0,buf,16);
			cout << "RECV L:" << l << endl;
		} else {
			if(FD_ISSET(0, &rd)) {
				cout << "something in set" << endl;
			} else {
				cout << "nothing in set" << endl;
			}
		}
	}
}
