#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char *argv[]) {
  int fd;
  char *line;
  int ret;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    return 1;
  }

  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  while ((line = get_next_line(fd)) != NULL) {
    printf("Line read: %s\n", line);
	free(line);
  }

  if (ret == NULL) {
    printf("get_next_line reach the end of file.\n");
  }

  free(line);
  close(fd);
  return 0;
}

