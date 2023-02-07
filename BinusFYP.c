#include <stdio.h>

//FYP
void fypA(), fypB(), fypC(), fypD(), fypE();

int main() { fypE(); return 0; }

void fypA()
{
	printf("Hello World!\n");
}

void fypB()
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n", a + b);
}

void fypC()
{
	int a, b, i;

	scanf("%d %d", &a, &b);

	for (i = a; i < a + b; i++) printf("%d\n", i);
}

void fypD()
{
	long long int a, b, result = 0, i;

	scanf("%lld %lld", &a, &b);

	for (i = a; i < b + 1; i++) result += i;

	printf("%lld\n", result);
}

void fypE()
{
	int input; scanf("%d", &input);

	printf(input % 2 == 0 ? "EVEN\n" : "ODD\n");
}