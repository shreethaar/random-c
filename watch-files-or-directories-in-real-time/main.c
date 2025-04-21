#include <stdio.h>
#include <sys/inotify.h>
#include <unistd.h>

int main() {
    int fd = inotify_init();
    int wd = inotify_add_watch(fd, "./index.html",IN_MODIFY);

    char buffer[4096];
    read(fd,buffer,sizeof(buffer));
    printf("File modified!\n");
    inotify_rm_watch(fd, wd);
    close(fd);
    return 0;
}

