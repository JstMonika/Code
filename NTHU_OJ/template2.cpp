#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char ch[3000];
	
	scanf("%d %s", &n, ch);
	
	n += 26 * 2000;
	n %= 26;
	
	int len = strlen(ch);
	for (int i = 0; i < len; i++)
		printf("%c", (ch[i] + n > 'z' ? ch[i] + n - 26 : ch[i] + n));
	printf("\n");
}