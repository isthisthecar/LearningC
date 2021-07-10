#include <stdio.h>
typedef struct tax {
   int value;
   int price;
   double rate;
}TAX;
void sub(TAX *a )
{
    printf("%f", a->value*a->price*a->rate);
}

int main()
{
      TAX elec={300, 2700, 5.7};
      sub( &elec );
      return 0;
}
