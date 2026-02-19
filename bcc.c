/*HI THIS IS THE MAIN FILE OF THE ULTIMATE BANANA COMPILER RAAH*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bcc.h"

int
x86_start(char *src, char *as) {
	FILE *source = fopen(src, "r"); /* cano geel */
    FILE *assembled = fopen(as, "a+");
	fprintf(assembled, ".section .text\n");
	fprintf(assembled, "_start:\n");
	fprintf(assembled, "jmp main\n");
	fprintf(assembled, "movl $1, %%eax\n");
	fprintf(assembled, "xorl %%ebx, %%ebx\n");
	fprintf(assembled, "int $0x80\n"); 

	fprintf(assembled, "main:\n");
	compile_x86(src, as);
	fprintf(assembled, "ret\n");
	exit(0);
}

	
int
main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("ERROR! Too little arguments\n");
		exit(1);
	}

	char *src = argv[2], *as = argv[3];
	switch(strcmp(argv[1], "x86")) {
		default:
			printf("Such arch does not exist OR the compiler does not support it currently.\n");
			exit(0);
			break;
		case 0:
			x86_start(src, as);
			break;
	}

}