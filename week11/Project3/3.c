#include<stdio.h>
#include<math.h>
float square(float num);
int main()
{
	float number = 0;
	printf("Please enter the number to be calculated:");
	scanf_s("%f", &number);
	printf("The square root of %f is %f.", number, square(number));
	return 0;
}
float square(float num)
{
	float result = 0;
	float h = num;
	float l = 0;
	float m = 0;
	m = (h + l) / 2;
	float temp=0;
	while((m * m - num >= 0.0001)|| (m * m - num <= -0.0001))
	{
		if (m * m > num)
		{
			h = m;
		}
		else
		{
			l = m;
		}
		m = (h + l) / 2;
	}
	result = m;
	return result;
}