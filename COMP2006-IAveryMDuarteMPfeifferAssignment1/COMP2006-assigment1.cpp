#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;

int updatedStudentIndex = -1;
vector<string> studentInfoList;
vector<int> userScores;

string fName;
string lName;
string answer1;
string answer2;
string answer3;
string answer4;

int score = 0;
int highScore = 0;
string fullName;

ifstream namesFile("names.txt");
string studentInfo;

bool hasName(string);
void saveStudentInfo();
void getStudentInfo();
void checkAnswers();

int main() {

	
	getStudentInfo();
	
	cout << "Please Enter Your First Name:";
	cin >> fName;
	cout << "Please Enter Your Last Name:";
	cin >> lName;
	fullName = fName + " " + lName;

	if (namesFile.is_open())
	{
		cout << "opened file, now reading.\n" << endl;
		if (hasName(fullName)) {
			cout << "Found!\n";
		}
		else {
			cout << "No user exits, create one!\n";

			ofstream writeFileNames("names.txt", ifstream::app);
			if (writeFileNames.is_open())
			{
				writeFileNames << fullName << endl;

				writeFileNames.close();

			}
		}

	}
	else
	{
		cout << "File is already open, close it!\n";
		ofstream writeFileNames("names.txt", ifstream::app);

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
	else cout << "Unable to open file.\n";

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

	checkAnswers();

	saveStudentInfo();

	cin.get();
	cin.get();

	return 0;
}

/*
*	This method will check if the user has an existing name in the names.txt file
*	and if not it will add the new user with their new score.
*/
bool hasName(string fullName) {
	int studentIndex = 0;
	
	while (getline(namesFile, studentInfo))
	{
		cout << fullName << " in " << studentInfo + "\n";
		if (studentInfo.find(fullName) != -1)
		{
			updatedStudentIndex = studentIndex;
			stringstream ss(studentInfo);
			string temp;
			int index = 1;
			while (getline(ss, temp, ' ')) // delimiter as space
			{
				if (index == 3) {

					cout << "Highscore : " << temp << endl;
				}
				else {
					cout << temp << endl;
				}
				index++;

			}
			return true;
		}
		studentIndex++;
	}
	return  false;
}


/*	split the string by white spaces and select the score. Store all scores
*	in a vector. Return the average based on the number of users score.
*/
void getAvgScore() {

	//read from the vector of user highscores

	//do the average and display to the user the average score
	int totalAvgScore = accumulate(userScores.begin(), userScores.end(), 0) / userScores.size();
	cout << "The average score is " << totalAvgScore << endl;

}

void getStudentInfo()
{

	ifstream studentsFile("names.txt");
	while (getline(studentsFile, studentInfo))
	{
		cout << studentInfo << endl;
		studentInfoList.push_back(studentInfo);
	}
	studentsFile.close();
}

void saveStudentInfo()
{
	if (updatedStudentIndex != -1) {
		cout << "Updating the student info with grade of 11";
		//cout << updatedStudentIndex;
		studentInfoList.at(updatedStudentIndex) = fullName + " " + "ll";
		cout << studentInfoList.at(updatedStudentIndex) << endl;


		ofstream updateFile("names.txt");
		if (updateFile.is_open())
		{
			for (int i = 0; i < studentInfoList.size(); i++) {
				updateFile << studentInfoList.at(i)<<"\n";
			}
			updateFile.close();

		}
	}
	else cout << "No update performed!" << endl;

}

/*
*	This Method will check the answers of the current user of the quiz dynamically and give a percentage
*		after completion. If the score is higher than thier previous than update score
*/
void checkAnswers()
{
	//local variables holding the value of correct answers
	float newAnswer1, newAnswer2, newAnswer3, newAnswer4;
	//Question 1
	cout << "Enter Answer For Question 1:";
	cin >> answer1;
	if (answer1 == "a") {
		newAnswer1 = 1;
		cout << "Correct!" << endl;
	}
	else {
		newAnswer1 = 0;
		cout << "Inorrect!" << endl;
	}
	//Question 2
	cout << "Enter Answer For Question 2:";
	cin >> answer2;
	if (answer2 == "a") {
		newAnswer2 = 1;
		cout << "Correct!" << endl;
	}
	else {
		newAnswer2 = 0;
		cout << "Inorrect!" << endl;
	}
	//Question 3
	cout << "Enter Answer For Question 3:";
	cin >> answer3;
	if (answer3 == "a") {
		newAnswer3 = 1;
		cout << "Correct!" << endl;
	}
	else {
		newAnswer3 = 0;
		cout << "Inorrect!" << endl;
	}
	//Question 4
	cout << "Enter Answer For Question 4:";
	cin >> answer4;
	if (answer4 == "a") {
		newAnswer4 = 1;
		cout << "Correct!" << endl;
	}
	else {
		newAnswer4 = 0;
		cout << "Inorrect!" << endl;
	}


}