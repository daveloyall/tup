#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

/* Clever wrapper function from Abdulla Kamar */
DIR *fdopendir(int fd)
{
	DIR *dir = opendir( "/" );

	if(!dir) {
		return NULL;
	} else if(close(dir->dd_fd)) {
		fprintf(stderr, "tup error: Unable to close fd in DIR\n");
		perror("close");
		return NULL;
	}

	dir->dd_fd = fd;
	rewinddir(dir);
	return dir;
}