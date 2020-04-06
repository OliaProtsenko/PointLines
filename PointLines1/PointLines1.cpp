// PointLines1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "g2.h"
#include "g2use.h"
using namespace  std;

string waytofile()
{
	string s;
	int n;
	cout << " if you want to change the file path press 1, leave default press 2" << endl;
	cin >> n;
	if (n == 1)
	{
		cout << "Enter please the file path:" << endl;
		cin >> s;
	}
	else
		s = "in.txt";
	return s;
}



void ProccesData(ifstream& f, ofstream& f1)
{
	string s, s1;
	Point m[4];
	const char* c;
	while (getline(f, s))
	{
		cout << 1;
		f1 << s;
		int n = s.length(), k, p, t;
		k = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '(')
			{
				i++;
				while (s[i] != ';')
				{
					s1 = s1 + s[i];
					i++;
				}
				c = s1.c_str();
				p = atof(c);
				s1 = "";
				i++;
				while (s[i] != ')')
				{
					s1 = s1 + s[i];
					i++;
				}
				c = s1.c_str();
				t = atof(c);
				m[k] = Point(p, t);
				k++;
				s1 = "";
			}
		}
		s = "";
		if (DifferentPoints(m[0], m[1], m[2], m[3]) == 1)
		{
			if (Opukluy(m[0], m[1], m[2], m[3]) == 1)
			{
				if (Trapetion(m[0], m[1], m[2], m[3]) == 1)
				{
					if (Opusana(m[0], m[1], m[2], m[3]) == 1)
						f1 << " Описана трапеція" << endl;
					else f1 << " Трапеція, але не є описаною" << endl;
				}
				else f1 << "    Чотирикутник опуклий,але немає двох паралельних сторін,або усі протилежні сторони паралельні між собою . Отже, не є трапецією" << endl;
			}
			else
				f1 << "   Чотирикутник не опуклий, а отже не є трапецією" << endl;
		}
		else f1 << "    Серед чотирьох вказаних точок є хоча б дві однакові, а отже задана ламана -не чотирикутник" << endl;


	}
}


void Information()
{
	cout << " Protsenko Olga K-14." << endl;
	cout << "This program check whether the polyline is a described trapezoid (v-23)"<<endl;
}
int main()
{
	string t;
	Information();
	t = waytofile();
	ifstream f(t);
	ofstream f1("out.txt");
	ProccesData(f, f1);
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
