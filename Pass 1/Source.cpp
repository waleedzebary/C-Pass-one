#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
void main() {
	char lable[100][100], s[100];
	int k = 0, i, j = 0, number_of_lable = 0;
	char s1[100], reg16[4][4] = { "ax","bx","cx","dx" },
		reg8[8][6] = { "ah","bh","ch","dh","al","bl","cl","dl" };
	int lenght = 0, reg1 = 0, reg2 = 0, reg3 = 0, reg4 = 0,
		r1 = 0, r2 = 0, r3 = 0, r4 = 0, y1 = 0, h1 = 0, z1 = 0;
	char* p = 0;
	int address = 0;
	FILE* fp;
	fp = fopen("abc.txt", "r+");
	if (fp == NULL)
	{
		cout << "Error in file";
		exit(0);
	}
	int t = 0;
	int number_of_comments = 0;
	cout << " --comments in the text : " << endl;
	while (!feof(fp))
	{
		fgets(s, 100, fp);
		for (i = 0; s[i] != '\0'; i++)
			if (s[i] == ';')
			{
				number_of_comments++;
				for (j = i; j < strlen(s) - 1; j++)
				{
					lable[k][t] = s[j];
					t++;
				}
				lable[k][t] = '\0';
				cout << lable[k];
				cout << endl;
				k++;
			}
		t = 0;
	}
	cout << " -- number of comments : " << number_of_comments << endl << endl;
	rewind(fp);
	while (!feof(fp))
	{
		fgets(s1, 100, fp);
		p = strtok(s1, ",");

		if (p)
		{
			for (int i = 0; i < 4; i++)
			{
				lenght = strspn(reg16[i], p);
				if (lenght == strlen(reg16[i]))
				{
					reg1++;
					r1 = 1;
					break;
				}
				else
					r1 = 0;
			}
			for (int j = 0; j < 8; j++)
			{
				lenght = strspn(reg8[j], p);
				if (lenght == strlen(reg8[j]))
				{
					reg2++;
					r2 = 1;
					break;
				}
				else
					r2 = 0;
			}
		}
		p = strtok(NULL, ",");
		if (p)
		{
			for (int i = 0; i < 4; i++)
			{
				lenght = strspn(reg16[i], p);
				if (lenght == strlen(reg16[i]))
				{
					reg3++;
					r3 = 1;
					break;
				}
				else
					r3 = 0;
			}
			for (int j = 0; j < 8; j++)
			{
				lenght = strspn(reg8[j], p);
				if (lenght == strlen(reg8[j]))
				{
					reg4++;
					r4 = 1;
					break;
				}
				else
					r4 = 0;
			}
			if ((r1 && r3 == 1) || (r2 && r4 == 1))
				address += 2;

			if ((r1 == 1) && (r2 + r3 + r4 + y1 == 0))
				address += 4;

			if ((r2 == 1) && (r1 + r3 + r4 + y1 == 0))
				address += 3;
		
		}
	}
	rewind(fp);

	cout << " --lable in the text : " << endl;
	while (!feof(fp))
	{
		fgets(s, 100, fp);
		
		for (i = 0; s[i] != '\0'; i++)
			if (s[i] == ':')
			{
				number_of_lable++;
				for (j = 0; j <= i; j++)
					lable[k][j] = s[j];
				lable[k][j] = '\0';

				cout << "The address is: " << address << " for the lable: ";
				cout << lable[k];
				cout << endl;
				k++;
			
			}
		
	}
	
	cout << " --number of lable : " << number_of_lable << endl << endl;
	address += 1;
	cout << " reg16 before=" << reg1 << endl << " reg8 before=" << reg2 << endl;
	cout << " reg16 after=" << reg3 << endl << " reg8 after =" << reg4 << endl;
	cout << address << endl;
	fclose(fp);
}
