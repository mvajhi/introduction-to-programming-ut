#include <stdio.h>
int main() {
int z = 4;
if (z - 4) {
int i = 1;
z = z + i;
}
else {
int i = 1;
z = i + 1;
{
int i = 1;
z = i + 1;
}
z = i;
}
/*z = z + i;*/
int i = 0;
do {
z = i + 1;
i++;
} while (i < 15);
printf("i in line 17 and 22 undefine.\n");
return 0;
}
