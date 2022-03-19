#include <stdio.h>
#include <stdlib.h>

unsigned long long maximum = 0;

int main() {
	unsigned long long blocksize[] = {1024 * 1024, 1024, 1};
	int i, count;

	for(i = 0; i < 3; i++) {
		for(count = 1;; count++) {
			void *block = malloc(maximum + blocksize[i] * count);
			if(block) {
				maximum = maximum + blocksize[i] * count;
				free(block);
			} else {
				break;
			}
		}
	}

	printf("maximum malloc size = %u bytes\n", maximum);
	return 0;
	
}
