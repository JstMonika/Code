#include <stdio.h>
#include <string.h>

int main()
{
   int n;
   char ch[3000];

   scanf("%d %s", &n, ch);

   n = n % 26;

   // ch[0] ~ ch[strlen(ch)-1].
   for (int i = 0; i < strlen(ch); i++)
   {
       if (ch[i] + n > 'z')
            ch[i] = ch[i] + n - 26;
        else 
            ch[i] = ch[i] + n;
   }
   
   printf("%s\n", ch);
}