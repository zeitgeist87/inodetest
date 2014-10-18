#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

#define NROOT_DIRS	1000
#define NDIRS		1000
#define NFILES		20

int main() {
	int i, j, k;
	char name_buf[128];

	for (i = 0; i < NROOT_DIRS; ++i) {
		snprintf(name_buf, sizeof(name_buf), "rootdir%d", i);
		mkdir(name_buf, 0700);
		chdir(name_buf);

		for (j = 0; j < NDIRS; ++j) {
			snprintf(name_buf, sizeof(name_buf), "dir%d", j);
			mkdir(name_buf, 0700);
			chdir(name_buf);

			for (k = 0; k < NFILES; ++k) {
				snprintf(name_buf, sizeof(name_buf), "file%d", k);
				int fd = creat(name_buf, 0600);
				if (fd != -1)
					close(fd);
				else
					perror("Error creating file");
			}

			chdir("..");
		}
		chdir("..");
	}
	return 0;
}
