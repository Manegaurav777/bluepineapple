#include <stdio.h>

int main(void) {
  int n;
  int count=0;
  printf("Enter a number\n");
  scanf("%d",&n);

  while(n!=0)
  {
    n=n/10;
    count++;
  }
printf("number of digits in a number is%d",count);
return 0;
}





