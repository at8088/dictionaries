#include <string.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s[10]="12345";
    char g[10]="";
    strncpy(g,s+1,3);
    printf("%s\n",g);
    printf("%c\n",g[2]);
    return 0;
}
