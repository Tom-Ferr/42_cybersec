#include <limits.h>
#include <stdio.h>

int main() {
    // Write C code here

	int a = INT_MIN + 11;
	int a_11 = a + 11;
	int a4 = a *= 4;
	size_t b = (size_t)a;

    printf("INT_MIN = %d\n",a);
    printf("INT_MIN - 11 = %d\n",a_11);
    printf("INT_MIN * 4 = %d\n",a4);
    printf("(size_t)(INT_MIN - 11) = %zu\n", b);
    return 0;
}
