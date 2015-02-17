#include <iostream>
#include <math.h>
using namespace std;

void dectostring(double dec,char *buf);
#define arraysize 24

int main()
{
	char storeresult[arraysize];
	double decinput;
	cout << "Please enter a decimal number" << endl;
	cin >> decinput;

	dectostring(decinput, storeresult);

	cout << storeresult << endl;

	system("pause");

	return 0;
}


void dectostring(double dec, char*buf)
{
	
	double nondec = floor(dec);
	double result = nondec;


	int pow10;

	for ( pow10 = 1;result / pow10 >= 1; pow10 *= 10);

	if(pow10 != 1)pow10 /= 10;
	int i;
	for ( i = 0; pow10 != 0 && i < arraysize; pow10 /= 10,i++)
	{
		int div = result / pow10;
		buf[i] = div + '0';
		result -= (div*pow10);
	}
	buf[i] = '.';

	double afterdec = dec - nondec;
	double pow10th;
	for (pow10th = 1; floor(afterdec * pow10th) != afterdec * pow10th; pow10th *= 10);

	double newdec = afterdec * pow10th;
	
	if(floor(pow10th)!= 1)pow10th /= 10;

	

	
	for (i+=1; floor(pow10th) >= 1 && i < arraysize; pow10th /= 10, i++)
	{
		int div = newdec / pow10th;
		buf[i] = div + '0';
		newdec -= (div*pow10th);
	}

	buf[i] = '\0';
}