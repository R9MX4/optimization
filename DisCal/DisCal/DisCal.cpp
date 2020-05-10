// DisCal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

bool between(double a, double X0, double X1)
{
	double temp1 = a - X0;
	double temp2 = a - X1;
	if ((temp1<1e-8 && temp2>-1e-8) || (temp2<1e-6 && temp1>-1e-8))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Cross(double A1[2], double A2[2], double B1[2], double B2[2])
{
	double line_x, line_y;
	if ((fabs(A1[0] - A2[0]) < 1e-6) && (fabs(B1[0] - B2[0]) < 1e-6))
	{
		return false;
	}
	else if ((fabs(A1[0] - A2[0]) < 1e-6))
	{
		if (between(A1[0], B1[0], B2[0]))
		{
			double k = (B2[1] - B1[1]) / (B2[0] - B1[0]);
			line_x = A1[0];
			line_y = k * (line_x - B1[0]) + B1[1];

			if (between(line_y, A1[1], A2[1]))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if ((fabs(B1[0] - B2[0]) < 1e-6))
	{
		if (between(B1[0], A1[0], A2[0]))
		{
			double k = (A2[1] - A1[1]) / (A2[0] - A1[0]);
			line_x = B1[0];
			line_y = k * (line_x - A2[0]) + A2[1];

			if (between(line_y, B1[1], B2[1]))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		double k1 = (A2[1] - A1[1]) / (A2[0] - A1[0]);
		double k2 = (B2[1] - B1[1]) / (B2[0] - B1[0]);

		if (fabs(k1 - k2) < 1e-6)
		{
			return false;
		}
		else
		{
			line_x = ((B1[1] - A1[1]) - (k2*B1[0] - k1 * A1[0])) / (k1 - k2);
			line_y = k1 * (line_x - A1[0]) + A1[1];
		}

		if (between(line_x, A1[0], A2[0]) && between(line_x, B1[0], B2[0]))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Cross2(double A1[2], double A2[2], double B1[2], double B2[2])
{
	if (
		(max(A1[0], A1[1]) >= min(B1[0], B1[1]) && min(A1[0], A1[1]) <= max(B1[0], B1[1])) &&
		(max(A2[0], A2[1]) >= min(B2[0], B2[1]) && min(A2[0], A2[1]) <= max(B2[0], B2[1]))
		)
	{
		if (
			((B1[0] - A1[0])*(A2[1] - A2[0]) - (B2[0] - A2[0])*(A1[1] - A1[0])) *
			((B1[1] - A1[0])*(A2[1] - A2[0]) - (B2[1] - A2[0])*(A1[1] - A1[0])) <= 0 &&
			((A1[0] - B1[0])*(B2[1] - B2[0]) - (A2[0] - B2[0])*(B1[1] - B1[0])) *
			((A1[1] - B1[0])*(B2[1] - B2[0]) - (A2[1] - B2[0])*(B1[1] - B1[0])) <= 0
			)
		{
			printf("(%f,%f),(%f,%f),(%f,%f),(%f,%f)\n", A1[0], A1[1], A2[0], A2[1], B1[0], B1[1], B2[0], B2[1]);
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

double Distance(double point1[2], double point2[2], double mountain[4][2])
{
	double dis = 0;
	bool cross = false;
	dis = sqrt(pow((point1[0] - point2[0]), 2) + pow((point1[1] - point2[1]), 2))*0.001;
	cross = Cross(point1, point2, mountain[0], mountain[1]) || Cross(point1, point2, mountain[2], mountain[3]);
	return cross == 0 ? dis : 100;
}

int main()
{
	double point[30][2], mountain[4][2], distance[30][30];
	int i, j;
	ifstream infile("Station.txt", ios::in);
	if (!infile)
		cout << "error1";
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 2; j++)
		{
			infile >> point[i][j];
		}
	}
	infile.close();
	ifstream infile2("Mountain.txt", ios::in);
	if (!infile2)
		cout << "error2";
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 2; j++)
		{
			infile2 >> mountain[i][j];
		}
	}
	infile2.close();


	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
			distance[i][j] = Distance(point[i], point[j], mountain);
	}
	ofstream outfile("Distance.txt", ios::out);
	for (i = 0; i < 30; i++)
	{
		for (j = 0; j < 30; j++)
			outfile << distance[i][j] << '\t';
		outfile << endl;
	}
	outfile.close();
	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
