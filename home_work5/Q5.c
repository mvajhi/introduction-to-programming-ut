void sort(int *a ,int *b, int *c)
{
	int tmp = 0;

	for (int i = 0; i < 2; i++)
	{
		if (*a > *b)
		{
			tmp = *a;
			*a = *b;
			*b = tmp;
		}

		if (*b > *c)
		{
			tmp = *c;
			*c = *b;
			*b = tmp;
		}
	}
}
