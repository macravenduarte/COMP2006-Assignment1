#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	//lets get some variables to store the user's info in
	string fname;
	string lname;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	int score = 0;

	// BEFORE THE TEST BEGINS, populate our quiz with some questions!
	//we call the file that we want to write, in this case quiz.txt inside of the project directory
	ofstream writeFile("quiz.txt");

	//if the file is not being used by another program
	if (writeFile.is_open())
	{
		//The basis of reading the different questions is that every question is broken into 5 lines, 1 for the question, 4 for the possible answers
		//modulus 5 allows us to know what line we are on
		writeFile << "What ends lines in C++?\n";		//line 1 
		writeFile << "SEMI-COLON\n";					//2 correct answer in ALL CAPS
		writeFile << "curly brace\n";					//3
		writeFile << "square bracket\n";				//4
		writeFile << "the number nine\n";				//5

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
	//else, we cannot read the file
	else cout << "Unable to open file";

	/*
	You must ask for the user’s first and last name then check if they have written the
	quiz before. If they have output their previous high score. If not welcome them.
	*/

	//WE NEED TO WELCOME THE USER

	/*
	You must read through the text file containing the quiz question followed by the
	four possible answers. The correct answer will be written in CAPITAL letters in the
	text file, but all answers should be displayed in lower case letters.
	*/

	//loop through the quiz file and read all the different answers
	//store the correct answer
	//store every line of info in our line string
	string line;
	ifstream readFile("quiz.txt"); //open a file reader to read quiz.txt
								   //if the file is not busy
	if (readFile.is_open())
	{
		//start at 0 for our line index
		int index = 0;
		string answer;

		//while there are lines in our file to read, we retreive that line of text into our line string
		while (getline(readFile, line))
		{
			//increment the index
			index++;
			//convert the line to lowercase for print out of the possible answers      
			string lowercase = line;
			transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);
			//convert the line to uppercase for answer comparison
			string uppercase = line;
			transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::toupper);

			//if the line we read is uppercase and not a question (!=1) that means that line is the answer
			if ((line == uppercase) && (index % 5 != 1))
			{
				switch (index % 5) 
				{
					case 2:
						answer = "A";
						break;
					case 3:
						answer = "B";
						break;
					case 4:
						answer = "C";
						break;
					case 0:
						answer = "D";
						break;
				}


				//print the line
				//if it is a question:      
				if (index % 5 == 1)
				{
					cout << "Question : " << line << '\n';
				}
				//if it is a possible answer print the letter and then the possible answer
				else
				{
					switch (index % 5)
					{
					case 2:
						cout << "A) ";
						break;
					case 3:
						cout << "B) ";
						break;
					case 4:
						cout << "C) ";
						break;
					case 0:
						cout << "D) ";
						break;
					}
					cout << lowercase << '\n';

					//if we are have finished printing the last possible question
					//ask user for answer
					if (index % 5 == 0)
					{
						string userAnswer;
						cout << "Enter Your Answer (A, B, C, or D):";
						cin >> userAnswer;
						transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::toupper);
						if (userAnswer == answer)
						{
							score++;
						}
					}
				}
			}//done reading the file
			readFile.close();
		}//end of while


		/*

		As you progress through the questions you will keep track of the users score. You

		should store the question dynamically, meaning only storing one question in

		memory at a time. */


		/*

		Once you’ve completed all the questions you will display the users

		score(percentage) then save it in the names.txt file in alphabetical order. If the user

		already has a score in the file you will only overwrite it if the new score is greater

		than the old score.
		*/

		/*
		After writing the quiz the user should be prompted if they would like to write the

		quiz again or quit.

		/*

		/*
		Bonus: Prior to administering the quiz calculate the average score of the quiz and include an

		additional message when user completes the quiz to see how they compare to the average.

		*/



		else cout << "Unable to open file";

		cout << "Enter Answer For Question 1:";
		cin >> answer1;
		cout << "Enter Answer For Question 2:";
		cin >> answer2;
		cout << "Enter Answer For Question 3:";
		cin >> answer3;
		cout << "Enter Answer For Question 4:";
		cin >> answer4;

		cout << "Please Enter Your First Name:";
		cin >> fname;
		cout << "Please Enter Your Last Name:";
		cin >> lname;

		ofstream writeFileNames("names.txt", fstream::app);
		if (writeFileNames.is_open())
		{
			writeFileNames << fname + " " + lname << score + "\n";
			writeFileNames.close();
		}

		cin.get();
		cin.get();

		return 0;
	}

}
