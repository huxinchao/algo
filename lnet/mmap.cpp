#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cstring>

constexpr int FILELENGTH = 80;
using namespace std;

int main() {
	int fd = -1;
	char buf[] = "quick brown fox jumps over the lazy dog";
	char *ptr = NULL;

	fd = open("note.txt", O_RDWR);

	if(-1 == fd) {
		return -1;
	}

	lseek(fd,FILELENGTH - 1, SEEK_SET);
	write(fd,"a",1);

	ptr = (char*)mmap(NULL, FILELENGTH, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if((char*)-1 == ptr) {
		cout << "mmap failed" << endl;
		close(fd);
		return -1;
	}

	memcpy(ptr + 16, buf, strlen(buf));
	munmap(ptr, FILELENGTH);

	return 0;
}
