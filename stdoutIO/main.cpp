#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char buf[1024 * 1024 * 1024];

int main(int argc, const char *argv[]) {
 // Initialize the buffer with some data.
 for (int i = 0; i < sizeof(buf); i++) {
   buf[i] = (char)i;
 }

 // Continuously write the buffer to standard output.
 while (true) {
   ssize_t bytes_written = write(STDOUT_FILENO, buf, sizeof(buf));
   if (bytes_written < 0) {
     perror("write to stdout error");
     return 1;
   }
 }

 return 0;
}
