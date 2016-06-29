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
string questionAnswer;
int score = 0;
int highScore = 0;
int totalQuestions = 0;
string fullName;
ifstream namesFile("names.txt");

//prototypes
bool hasName(string);
void saveStudentInfo();
void getStudentInfoFromList();
string readQuestion(int, string);
void getAnswerFromUser(string);
void writeQuizQuestions();
int getHighScore(int);

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
        int index = 0;
        string answer;

        while (getline(readFile, line))
        {
            index++;
            string answerToQ = readQuestion(index,line);
            if(answerToQ!=""){
                answer = answerToQ;
            }
            if(index % 5 == 0){
                getAnswerFromUser(answer);

            }
        }
        readFile.close();
    }

    else cout << "Unable to open file" << endl;


    saveStudentInfo();

    cout << "Would you like to do the quiz again?"<<endl;

    cin.get();
    cin.get();

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
        cout << "Question " << to_string(((index-1)/5)+1) <<endl;
        cout << line << '\n';
        totalQuestions += 1;
    }
    else {
        switch (index % 5) {
            case 2:
                if(line.compare(uppercase)==0){
                    questionAnswer = "A";
                }
                cout << "a) ";
                break;
            case 3:
                if(line.compare(uppercase)==0){
                    questionAnswer = "B";
                }
                cout << "b) ";
                break;
            case 4:
                if(line.compare(uppercase)==0){
                    questionAnswer = "C";
                }
                cout << "c) ";
                break;
            case 0:
                if(line.compare(uppercase)==0){
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
void getAnswerFromUser(string answer){
    cout << "What is your answer?";
    cin >> userAnswer;
    transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::toupper);
    if(userAnswer.compare(answer)==0){
        score ++;
    }
    cout << "Your score is: " << score << endl;
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
        int finalScore=(score/totalQuestions)*100;
        cout << "Your final score is " << to_string(finalScore) <<endl;
        if(finalScore > highScore){
            cout << "Updating the student info with their new score " << to_string(finalScore) <<
            " ("<< to_string(score) << " out of "<< to_string(totalQuestions) << ")"<< endl;
            //cout << updatedStudentIndex;
            studentInfoList.at(updatedStudentIndex) = fullName + " " + to_string(finalScore);
            cout << studentInfoList.at(updatedStudentIndex) << endl;
        }else{
            cout << "Try again! You got "<< to_string(score) << " your high score is " << to_string(highScore) << endl;
        }
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


