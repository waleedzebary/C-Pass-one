#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void main()
{
	char letter_1[20] = "hello world";
	char *p = nullptr;
	p = strstr(letter_1, "o");
	if (p != nullptr)
	{
		cout << "The letter is found: " << p << endl;
		cout << "The location is: " << &p << endl;
	}
	else
	{
		cout << "The letter is not found...." << endl;
	}

	string st, st_2 = "world!";
	cout << "Enter the string: ";
	getline(cin, st);
	cout << st << st_2 << endl;

	char first_name[20];
	char last_name[20];
	cout << "Enter the characters first name: ";
	cin >> first_name;
	cout << "Enter the characters second name: ";
	cin >> last_name;
	if (strcmp(first_name, last_name) == 0)
	{
		cout << "The string is Equal: " << first_name << " = " << last_name << endl;
	}
	else
	{
		cout << "The string is not Equal: " << first_name << " != " << last_name << endl;
	}
	strcat_s(first_name, last_name);
	cout << "The string cat is: " << first_name << endl;
	strcpy_s(first_name, last_name);
	cout << "The string copy is: " << first_name << endl;
	string name_first;
	string name_last;
	cout << "Enter the string first name: ";
	cin >> name_first;
	cout << "Enter the string second name: ";
	cin >> name_last;
	if (name_first == name_last)
	{
		cout << "The string is Equal: " << name_first << " = " << name_last << endl;
	}
	else
	{
		cout << "The string is not Equal: " << name_first << " != " << name_last << endl;
	}
	name_first = name_last;
	cout << "The string is: " << name_first << endl;
	string name_1;
	string name_2;
	cout << "Enter the string first name to now length: ";
	cin >> name_1;
	cout << "Enter the string second name to now length: ";
	cin >> name_2;
	int length_1 = name_1.length();
	int length_2 = name_2.length();
	if (name_1.length() == name_2.length())
	{
		cout << "The length is Equal of the string: " << length_1 << " = " << length_2 << endl;
	}
	else
	{

		cout << "The length is not Equal of the string: " << length_1 << " != " << length_2 << endl;
	}

	string st_1;
	cout << "Enter the string: ";
	cin >> st_1;
	cout << "The string is: " << st_1.at(2) << endl;
	cout << "The string is back: " << st_1.back() << endl;
	char ch_1[30];
	strcpy_s(ch_1, st_1.c_str());
	cout << "The characters is: " << ch_1 << endl;
	char ch_2[30] = "123456789";
	cout << "The characters number is: " << ch_2 << endl;
	int number_1 = atoi(ch_2);
	cout << "The number is: " << number_1 << endl;
	string number = to_string(number_1);
	cout << "The string number is: " << number << endl;

}