#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

string fName;
string lName;
string answer1;
string answer2;
string answer3;
string answer4;
string studentInfo;
int score = 0;
int highScore = 0;
string fullName;

ifstream namesFile("names.txt");
stringstream stringStream(studentInfo);
bool hasName(string);
int main() {

	cout << "Please Enter Your First Name:";
	cin >> fName;
	cout << "Please Enter Your Last Name:";
	cin >> lName;
	fullName = fName + " " + lName;

	if (namesFile.is_open())
	{
		if (hasName(fullName)) {
			cout << "Found!";
		}
		else {
			cout << "No user exits, create one!";

		}

	}
	else
	{
		ofstream writeFileNames("names.txt", fstream::app);
		if (writeFileNames.is_open())
		{
			writeFileNames << fullName + "\n";

			writeFileNames.close();

		}
	}






	ofstream writeFile("quiz.txt");
	if (writeFile.is_open())
	{
		writeFile << "What ends lines in C++?\n";
		writeFile << "SEMI-COLON\n";
		writeFile << "curly brace\n";
		writeFile << "square bracket\n";
		writeFile << "the number nine\n";
		writeFile << "What is C++?\n";
		writeFile << "PROGRAMMING LANGUAGE\n";
		writeFile << "variable\n";
		writeFile << "class\n";
		writeFile << "array\n";
		writeFile << "What does COUT do?\n";
		writeFile << "OUTPUT\n";
		writeFile << "get input\n";
		writeFile << "array\n";
		writeFile << "read from file\n";
		writeFile << "What Does CIN do?\n";
		writeFile << "GET INPUT\n";
		writeFile << "output data\n";
		writeFile << "read file\n";
		writeFile << "write to file\n";
		writeFile.close();

	}
	else cout << "Unable to open file";

	string line;
	ifstream readFile("quiz.txt");
	if (readFile.is_open())
	{
		int index = 0;
		string answer;

		while (getline(readFile, line))
		{
			index++;
			string lowercase = line;
			transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
			string uppercase = line;
			transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::toupper);

			if (index % 5 == 1) {
				cout << "Question : " << line << '\n';
			}
			else {
				switch (index % 5) {
				case 2:
					cout << "a) ";
					break;
				case 3:
					cout << "b) ";
					break;
				case 4:
					cout << "c) ";
					break;
				case 0:
					cout << "d) ";
					break;


				}
				cout << lowercase << '\n';
			}
		}
		readFile.close();
	}

	else cout << "Unable to open file";
	cout << "Enter Answer For Question 1:";
	cin >> answer1;
	cout << "Enter Answer For Question 2:";
	cin >> answer2;
	cout << "Enter Answer For Question 3:";
	cin >> answer3;
	cout << "Enter Answer For Question 4:";
	cin >> answer4;


	cin.get();
	cin.get();

	return 0;
}
bool hasName(string fullName) {
	while (getline(namesFile, studentInfo))
	{
		cout << fullName << " in " << studentInfo + "\n";
		if (studentInfo.find(fullName) != -1)
		{
			string temp = "";
			while (getline(stringStream, temp, ' ')) // delimiter as space
			{
				cout << temp << endl;
			}

			highScore = 100;
			return true;
		}
	}
	return  false;
}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

string fName;
string lName;
string answer1;
string answer2;
string answer3;
string answer4;
string studentInfo;
int score = 0;
int highScore = 0;
string fullName;

ifstream namesFile("names.txt");
bool hasName(string);
int main() {

	cout << "Please Enter Your First Name:";
	cin >> fName;
	cout << "Please Enter Your Last Name:";
	cin >> lName;
	fullName = fName + " " + lName;

	if (namesFile.is_open())
	{
		if (hasName(fullName)) {
			cout << "Found!";
		}
		else {
			cout << "No user exits, create one!";

		}

	}
	else
	{
		ofstream writeFileNames("names.txt", fstream::app);
		if (writeFileNames.is_open())
		{
			writeFileNames << fullName + "\n";

			writeFileNames.close();

		}
	}






	ofstream writeFile("quiz.txt");
	if (writeFile.is_open())
	{
		writeFile << "What ends lines in C++?\n";
		writeFile << "SEMI-COLON\n";
		writeFile << "curly brace\n";
		writeFile << "square bracket\n";
		writeFile << "the number nine\n";
		writeFile << "What is C++?\n";
		writeFile << "PROGRAMMING LANGUAGE\n";
		writeFile << "variable\n";
		writeFile << "class\n";
		writeFile << "array\n";
		writeFile << "What does COUT do?\n";
		writeFile << "OUTPUT\n";
		writeFile << "get input\n";
		writeFile << "array\n";
		writeFile << "read from file\n";
		writeFile << "What Does CIN do?\n";
		writeFile << "GET INPUT\n";
		writeFile << "output data\n";
		writeFile << "read file\n";
		writeFile << "write to file\n";
		writeFile.close();

	}
	else cout << "Unable to open file";

	string line;
	ifstream readFile("quiz.txt");
	if (readFile.is_open())
	{
		int index = 0;
		string answer;

		while (getline(readFile, line))
		{
			index++;
			string lowercase = line;
			transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
			string uppercase = line;
			transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::toupper);

			if (index % 5 == 1) {
				cout << "Question : " << line << '\n';
			}
			else {
				switch (index % 5) {
				case 2:
					cout << "a) ";
					break;
				case 3:
					cout << "b) ";
					break;
				case 4:
					cout << "c) ";
					break;
				case 0:
					cout << "d) ";
					break;


				}
				cout << lowercase << '\n';
			}
		}
		readFile.close();
	}

	else cout << "Unable to open file";
	cout << "Enter Answer For Question 1:";
	cin >> answer1;
	cout << "Enter Answer For Question 2:";
	cin >> answer2;
	cout << "Enter Answer For Question 3:";
	cin >> answer3;
	cout << "Enter Answer For Question 4:";
	cin >> answer4;


	cin.get();
	cin.get();

	return 0;
}
bool hasName(string fullName) {
	while (getline(namesFile, studentInfo))
	{
		cout << fullName << " in " << studentInfo + "\n";
		if (studentInfo.find(fullName) != -1)
		{
			string temp = "";
			highScore = 100;
			return true;
		}
	}
	return  false;
}

