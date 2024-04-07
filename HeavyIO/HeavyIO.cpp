#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char buf[1024 * 1024 * 1024];

int main(int argc, const char *argv[]) {
  int fd = open("/dev/null", O_WRONLY);
  for (int i = 0; i < sizeof(buf); i++) {
    buf[i] = (char)i;
  }
  while (true) {
    ssize_t bytes_written = write(fd, buf, sizeof(buf));
    if (bytes_written < 0) {
      perror("write file error");
      return 1;
    }
  }

  close(fd);

  return 0;
}