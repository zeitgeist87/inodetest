#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

static void usage(char **argv){
	char *progname;

	if ((progname = strrchr(argv[0], '/')) != NULL)
		progname++;
	else
		progname = argv[0];

	printf("Usage: %s NROOT_DIRS NDIRS NFILES\n", progname);
}

int main(int argc, char **argv) {
	int i, j, k;
	int nroot, ndirs, nfiles;
	char name_buf[128];

	if (argc < 4) {
		usage(argv);
		return EXIT_FAILURE;
	}

	nroot = atoi(argv[1]);
	ndirs = atoi(argv[2]);
	nfiles = atoi(argv[3]);

	for (i = 0; i < nroot; ++i) {
		snprintf(name_buf, sizeof(name_buf), "rootdir%d", i);
		mkdir(name_buf, 0700);
		chdir(name_buf);

		for (j = 0; j < ndirs; ++j) {
			snprintf(name_buf, sizeof(name_buf), "dir%d", j);
			mkdir(name_buf, 0700);
			chdir(name_buf);

			for (k = 0; k < nfiles; ++k) {
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
