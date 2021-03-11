#include <iostream>
#include <utmp.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

const int NRECS = 16;
utmp* UTNULL = NULL;
const int UTSIZE = sizeof(utmp);

static char utmpbuf[NRECS * UTSIZE];
static int num_recs;
static int cur_rec;
static int fd_utmp = -1;

int utmp_open(char*);
utmp* utmp_next();
int utmp_reload();
void utmp_close();
void show_info(utmp* ut);

int utmp_open(char* filename) {
  fd_utmp = open(filename, O_RDONLY);
  cur_rec = num_recs = 0;
  return fd_utmp;
}

utmp* utmp_next() {
  utmp* recp;
  if(fd_utmp == -1) {
    return UTNULL;
  }
  
  if(cur_rec == num_recs && utmp_reload() == 0) {
    return UTNULL;
  }

  recp = (utmp*)&utmpbuf[cur_rec * UTSIZE];
  cur_rec++;
  return recp;
}

int utmp_reload() {
  int amt_read;
  amt_read = read(fd_utmp, utmpbuf, NRECS * UTSIZE);
  num_recs = amt_read / UTSIZE;
  cur_rec = 0;
  return num_recs;
}

void utmp_close() {
  if(fd_utmp != -1) {
    
    close(fd_utmp);
  }
}

void show_info(utmp* ut) {
  std::cout << ut->ut_name << std::endl;
}

int main(int ac, char *av[]) {
  utmp* utbufp;
  if(utmp_open(UTMP_FILE) == -1) {
    std::cerr << UTMP_FILE << std::endl;
    exit(1);
  }
  while((utbufp = utmp_next()) != NULL) {
    show_info(utbufp);
  }
  utmp_close();
  return 0;
}

