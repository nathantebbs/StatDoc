#include "include/stdi.h"

int main(int argc, char* argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: ./statdoc <input.std>\n");
		fprintf(stderr, "ERROR: expected input\n");
		exit(1);
	}

	printf("Welcome To StatDoc!");
	return 0;
}
