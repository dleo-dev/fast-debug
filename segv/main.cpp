#include <iostream>
#include <csignal>

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <unistd.h>
}

void segvHandler(int sig) {
	int maxDepth = 16;
	void *stack[maxDepth];
	int depth = backtrace(stack, maxDepth);
	backtrace_symbols_fd(stack + 1, depth - 1, STDOUT_FILENO);
	exit(1);
}

void causeSegv() {
	char **argv;
	argv[10000] = (char *)"SEGV";
}

int main(int argc, char *argv[]) {
	signal(SIGSEGV, segvHandler);
	causeSegv();
}



