#include <iostream>
using namespace std;
int main()
{
	float g_p = 0;
	float g_d = 0;
	float g_p2 = 0;
	float g_d2 = 0;
	float ratio = 0.327232069; //the square root value of the hand calculated needed speed ratio
	float P_array[18];
	float D_array[18];
	float P_array2[18];
	float D_array2[18];
	float min = 10.00;
	float counter = 10.0; //lowest number of teeth possible

	for (int p = 0; p < 18; p++) //populates pinion array from 10 - 27
		P_array[p] = counter++;
	counter = 10.00;
	for (int p = 0; p < 18; p++) // populates drive array from 10 - 27
		D_array[p] = counter++;
	counter = 10.00;
	for (int p = 0; p < 18; p++) //populates pinion array from 10 - 27
		P_array2[p] = counter++;
	counter = 10.00;
	for (int p = 0; p < 18; p++) // populates drive array from 10 - 27
		D_array2[p] = counter++;

	for (int i = 0; i < 18; i++)
	{
		for (int x = 0; x < 18; x++) //iterates all driven values for every 1 pinion value (289 calculations total)
		{
			for (int i1 = 0; i1 < 18; i1++)
			{
				for (int x1 = 0; x1 < 18; x1++)
				{
					if (abs((P_array[i] / D_array[x]) * (P_array2[i1] / D_array2[x1]) - ratio) <= min && P_array[i] < D_array[x] && P_array2[i1] < D_array2[x1]) // finds the smallest number from the ratio of every combination of pinion to driven by subtracting it from the calculated ratio
					{
						g_p = P_array[i];
						g_d = D_array[x];
						g_p2 = P_array2[i1];
						g_d2 = D_array2[x1];
						min = abs((g_p / g_d) * (g_p2 / g_d2) - ratio); //updates value of min so ratios of greater magnitude will not clear if condition
					}
				}
			}
		}
	}
	cout << g_p << " and " << g_d << endl; // displays pinion and drive gear
	cout << g_p2 << " and " << g_d2 << endl;
	cout << "the desired ratio is: " << ratio << endl; // displays desired ratio	
	cout << "the ratio rounded is: " << ((g_p / g_d) * (g_p2 / g_d2)) << endl; // displays actual whole number ratio
	cout << "margin of error is: " << ((ratio - ((g_p / g_d) * (g_p2 / g_d2))) / ratio) * 100 << "%" << endl; //displays error %
}