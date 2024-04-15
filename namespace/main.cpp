#include <cstdio>
#include <sched.h>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

static char childStack[4096];

const char *const childArgs[] = {
    "/bin/bash", "-c", "mount --make-private -t proc proc /proc && /bin/bash",
    nullptr};

/*
Here's how you can revert the private mount of the /proc filesystem:

Unmount the Private /proc:
Use the umount command to unmount the /proc filesystem that was previously
mounted as private.
    umount /proc

Remount the /proc:
After unmounting, you can remount /proc with the default options, which
typically do not include the --make-private flag.
    mount -t proc proc /proc
*/

int child_main(void *args) {
  printf("launch child process\n");
  std::string newHostName = "winlic-d1.muc";
  sethostname(newHostName.data(), newHostName.size());
  execv(childArgs[0], const_cast<char *const *>(&childArgs[0]));
  return 0;
}

int main() {
  constexpr int flag =
      CLONE_NEWNS | CLONE_NEWPID | CLONE_NEWIPC | CLONE_NEWUTS | SIGCHLD;
  /*
  The flags passed to clone() specify which namespaces
  the child process willhave:
    CLONE_NEWNS: New mount namespace.
    CLONE_NEWPID: New PID namespace.
    CLONE_NEWIPC: New IPC namespace.
    CLONE_NEWUTS: New UTS namespace. The SIGCHLD flag indicates that the parent
    process will receive this signal when the child process terminates.
  */
  pid_t child =
      clone(child_main, &childStack[sizeof(childStack)], flag, nullptr);
  if (child >= 0) {
    waitpid(child, nullptr, 0);
    printf("exit child process\n");
  } else {
    perror("clone failed");
  }
  return 0;
}