float calc_mean(float *data_array)
{

	int sum = 0;

	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		sum += data_array[i];
	}
	return (float)sum / ARRAY_LENGTH;
}

float calc_standard_deviation(float *data_array)
{
	float mean = calc_mean(data_array);
	int sum = 0;

	for (int i = 0; i < ARRAY_LENGTH; i++)
	{
		sum += pow(data_array[i] - mean, 2);
	}
	return (float)sqrt(sum / ARRAY_LENGTH);
}

float calc_cv(float *data_array)
{
	return calc_standard_deviation(data_array) / calc_mean(data_array);
}
