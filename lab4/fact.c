#include "fact.h"

int fact(int x)
{
	if (x > 1)
	{
		return x * fact(x - 1);
	}
	else
	{
		return 1;
	}
}

