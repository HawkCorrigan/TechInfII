/* gcc -Wall -O2 caching.c -o caching */
/* ./pepare_perf           */
/* ./perf stat ./caching 0 */
/* ./perf stat ./caching 1 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void f(char **addr, size_t x, size_t y)
{
	/* Traverse data, method 1 */
	/* ... */

	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			*(*(addr+i)+j) += 1;
		}
	}
}

static void g(char **addr, size_t x, size_t y)
{
	/* Traverse data, method 2 */
	/* ... */

	for(int j=0; j<y; j++){
		for(int i=0; i<x; i++){
			*(*(addr+i)+j) += 1;
		}

	}
}

int main(int argc, char **argv)
{
	char **addr;
	size_t x, y;
	int i;

	if (argc != 2) {
		printf("Usage: ./a.out <test-nr:0|1>\n");
		return -EIO;
	}

	x = y = sysconf(_SC_PAGE_SIZE) * 5;
	addr = valloc(x * sizeof(char *));
	if (addr == NULL)
		return -ENOMEM;

	for (i = 0; i < x; i++) {
		addr[i] = malloc(y * sizeof(char));
		if (addr[i] == NULL)
			return -ENOMEM;
	}

	switch (atoi(argv[1])) {
	default:
	case 0:
		f(addr, x, y);
		break;
	case 1:
		g(addr, x, y);
		break;
	}


	for (i = 0; i < x; i++)
		free(addr[i]);
	free(addr);
	return 0;
}
