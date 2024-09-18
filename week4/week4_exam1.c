#include <stdio.h>

int main() {
	char message[5] = {'a', 'b', 'c', '\0'};
	char message2[5] = { 'a', 'b','c','d','e'};

	printf("message = %s, message2 = %s", message, message2);

	return 0;
}