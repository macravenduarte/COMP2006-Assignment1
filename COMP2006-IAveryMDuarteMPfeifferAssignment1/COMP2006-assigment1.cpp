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
string userAnswer;
string studentInfo;
int score = 0;
int newScore = 0;
int highScore = 0;
int totalQuestions = 0;
string fullName;
ifstream namesFile("names.txt");

//prototypes
bool hasName(string);
void saveStudentInfo();
void getStudentInfoFromList();
string readQuestion(int, string);
void getAnswerFromUser(string, int);
void writeQuizQuestions();
int getHighScore(int);
void getNewHighScore(int, int);

int main() {


    getStudentInfoFromList();

    cout << "Please Enter Your First Name:";
    cin >> fName;
    cout << "Please Enter Your Last Name:";
    cin >> lName;
    fullName = fName + " " + lName;

    if (namesFile.is_open())
    {
        cout << "opened file, now reading" << endl;
        if (hasName(fullName)) {
            cout << "Welcome " << fullName << ", your previous score is " << highScore <<  endl;
        }
        else {
            cout << "No user exits, create one!" << endl;
            ofstream writeFileNames("names.txt", fstream::app);
            if (writeFileNames.is_open())
            {
                writeFileNames << fullName + "\n";

                writeFileNames.close();

            }
        }

    }
    else
    {
        cout << "File is already open, close it!" << endl;
    }

    writeQuizQuestions();

    string line;
    ifstream readFile("quiz.txt");
    if (readFile.is_open())
    {
        int index = 0, question = 1;
        string answer;

        while (getline(readFile, line))
        {
            index++;
            answer = readQuestion(index,line);
			if (index % 5 == 0) {
				getAnswerFromUser(answer,question);
				question = question + 1;
			}
            
        }
        readFile.close();
    }

    else cout << "Unable to open file" << endl;
	
    saveStudentInfo();

    return 0;
}
/*
 * This method will write the questions to the quiz file
 */

void writeQuizQuestions(){
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
    else cout << "Unable to open file" << endl;
}
/*
 * This method will read the question one at a time
 * and return the answer to that question
 */
string readQuestion(int index, string line){
    string questionAnswer = "";
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
                if(line.compare(uppercase)!=0){
                    questionAnswer = "A";
                }
                cout << "a) ";
                break;
            case 3:
                if(line.compare(uppercase)!=0){
                    questionAnswer = "B";
                }
                cout << "b) ";
                break;
            case 4:
                if(line.compare(uppercase)!=0){
                    questionAnswer = "C";
                }
                cout << "c) ";
                break;
            case 0:
                if(line.compare(uppercase)!=0){
                    questionAnswer = "D";
                }
                cout << "d) ";
                break;


        }
        cout << lowercase << '\n';

    }
    //TO DO, return the answer
    return questionAnswer;
}
/*
 * This method will retrieve the answer from the user and compare against the answer
 * if true increment the score
 */
void getAnswerFromUser(string answer, int question){

	switch (question) {
		//Question 1
		case 1:
			cout << "Enter Answer For Question 1:";
			cin >> answer1;
			if (answer1 == "a") {
				newScore = newScore + 1;
				cout << "Correct!" << endl;

			}
			else {
				cout << "Inorrect!" << endl;

			}
			break;

		//Question 2
		case 2:
			cout << "Enter Answer For Question 2:";
			cin >> answer2;
			if (answer2 == "a") {
				newScore = newScore + 1;
				cout << "Correct!" << endl;

			}
			else {
				cout << "Inorrect!" << endl;

			}
			break;

		//Question 3
		case 3:
			cout << "Enter Answer For Question 3:";
			cin >> answer3;
			if (answer3 == "a") {
				newScore = newScore + 1;
				cout << "Correct!" << endl;

			}
			else {
				cout << "Inorrect!" << endl;

			}
			break;
		//Question 4
		case 4:
			cout << "Enter Answer For Question 4:";
			cin >> answer4;
			if (answer4 == "a") {
				newScore = newScore + 1;
				cout << "Correct!" << endl;

			}
			else {
				cout << "Inorrect!" << endl;
			}
			break;

	}
			
	score = newScore;
    cout << "Your Score Is:" << newScore << endl;
	
}

bool hasName(string fullName) {
    int studentIndex = 0;

    while (getline(namesFile, studentInfo))
    {
        cout << fullName << " in " << studentInfo + "\n";
        if (studentInfo.find(fullName) != -1)
        {
            updatedStudentIndex = studentIndex;
            highScore = getHighScore(updatedStudentIndex);

            return true;
        }
        studentIndex++;
    }
    return  false;
}
/*
 * This method will return the high score of the student's information
 */
int getHighScore(int studentIndex) {
    stringstream ss(studentInfoList.at(studentIndex));
    string temp;
    int index = 1;
    while (getline(ss, temp, ' ')) // delimiter as space
    {
        if (index == 3) {
            return stoi(temp);
        }
        index++;
    }
    return -1;
}

/*	split the string by white spaces and select the score. Store all scores
*	in a vector. Return the average based on the number of users score.
*/
int getAvgScore() {

    int totalAvgScore = accumulate(userScores.begin(), userScores.end(), 0) / userScores.size();
    cout << "The average score is " << totalAvgScore << endl;

    return 0;
}

void getStudentInfoFromList()
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

    ofstream updateFile("names.txt");

    if (updatedStudentIndex != -1) {
        cout << "Updating the student info with their high score" << endl;
        //cout << updatedStudentIndex;
        studentInfoList.at(updatedStudentIndex) = fullName + " " + to_string(highScore);
        cout << studentInfoList.at(updatedStudentIndex) << endl;
    }else {
        cout << "Adding the new student info with their high score" << endl;
        //cout << updatedStudentIndex;
        studentInfoList.push_back(fullName + " " + to_string(highScore));
    }
    //added sort alphabetically
    sort(studentInfoList.begin(), studentInfoList.end());

    if (updateFile.is_open())
    {
        for (int i = 0; i < studentInfoList.size(); i++) {
            updateFile << studentInfoList.at(i)<<"\n";
        }
        updateFile.close();

    }

}

void getNewHighScore(int newScore, int score){

		if (newScore > score) {
			newScore = (score / 4) * 100;
			highScore = newScore;
			cout << "New High Score of " << highScore << endl;
		}

}
