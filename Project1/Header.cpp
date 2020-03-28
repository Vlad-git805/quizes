#include "Header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Quiz *quiz;
int countQuiz = 0;

int coq = 0;
int coa = 0;
int *countOfQuestions = new int[coq];
int *countOfAnswers = new int[coa];

//void init()
//{
//	int currentString = 0;
//	int currentString2 = 0;
//	string data;
//	ifstream fin;
//	fin.open("Quiz.txt");
//	bool isOpen = fin.is_open();
//	if (isOpen == false)
//	{
//		cout << "Error" << endl;
//	}
//	else
//	{
//		while (!fin.eof())
//		{
//			currentString++;
//			getline(fin, data);
//		}
//		currentString2 = (currentString - 1) / 11;
//		currentString = 0;
//	}
//	fin.close();
//	countQuiz = currentString2;
//	Quiz *temp1 = new Quiz[currentString2];
//	int f = 0;
//	fin.open("Quiz.txt");
//	bool isOpenn = fin.is_open();
//	if (isOpenn == false)
//	{
//		cout << "Error" << endl;
//	}
//	else
//	{
//		while (!fin.eof())
//		{
//			currentString++;
//			getline(fin, data);
//			for (int i = f; i < currentString2;)
//			{
//				if (currentString == 1)
//				{
//					temp1[i].question = new Questions[5];
//					temp1[i].nameQuiz = data;
//					break;
//				}
//				else if (currentString == 2)
//				{
//					temp1[i].question[0].question1 = data;
//					break;
//				}
//				else if (currentString == 3)
//				{
//					temp1[i].question[0].answer = data;
//					break;
//				}
//				else if (currentString == 4)
//				{
//					temp1[i].question[1].question1 = data;
//					break;
//				}
//				else if (currentString == 5)
//				{
//					temp1[i].question[1].answer = data;
//					break;
//				}
//				else if (currentString == 6)
//				{
//					temp1[i].question[2].question1 = data;
//					break;
//				}
//				else if (currentString == 7)
//				{
//					temp1[i].question[2].answer = data;
//					break;
//				}
//				else if (currentString == 8)
//				{
//					temp1[i].question[3].question1 = data;
//					break;
//				}
//				else if (currentString == 9)
//				{
//					temp1[i].question[3].answer = data;
//					break;
//				}
//				else if (currentString == 10)
//				{
//					temp1[i].question[4].question1 = data;
//					break;
//				}
//				else if (currentString == 11)
//				{
//					temp1[i].question[4].answer = data;
//					currentString = 0;
//					f++;
//					break;
//				}
//			}
//		}
//		quiz = temp1;
//	}
//	fin.close();
//}

void init2()
{
	int currentString = 0;
	int currentString2 = 0;
	int data;
	ifstream fin;
	fin.open("Data.txt");
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			currentString++;
			fin >> data;
		}
		currentString2 = (currentString - 1) / 2;
		currentString = 0;
		coq = currentString2;
	}
	fin.close();
	int *temp1 = new int[currentString2];
	int *temp2 = new int[currentString2];
	int f = 0;
	fin.open("Data.txt");
	bool isOpenn = fin.is_open();
	if (isOpenn == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			currentString++;
			fin >> data;
			for (int i = f; i < currentString2;)
			{
				if (currentString == 1)
				{
					temp1[i] = data;
					break;
				}
				else if (currentString == 2)
				{
					temp2[i] = data;
					currentString = 0;
					f++;
					break;
				}
			}
		}

		countOfQuestions = temp1;
		countOfAnswers = temp2;
	}
	fin.close();
}


void insertQuiz(Quiz quizz)
{
	Quiz *temp = new Quiz[countQuiz + 1];
	for (int i = 0; i < countQuiz; i++)
	{
		/*temp[i].nameQuiz = quiz[i].nameQuiz;
		for (int j = 0; j < coq; j++)
		{
			temp[i].question[j].question1 = quiz[i].question[j].question1;
			for (int k = 0; k < coa; k++)
			{
				temp[i].question[j].answer[k].answer1 = quiz[i].question[j].answer[k].answer1;
			}
		}*/
		temp[i] = quiz[i];
	}
	temp[countQuiz] = quizz;
	countQuiz++;
	quiz = new Quiz[countQuiz];
	for (int i = 0; i < countQuiz; i++)
	{
		quiz[i] = temp[i];
	}
	delete[] temp;
}

void init()
{
	/*for (int i = 0; i < countQuiz; i++)
	{
		coq = countOfQuestions[i];
		coa = countOfAnswers[i];
	}*/
	
	ifstream fin;
	fin.open("Quiz.txt");
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			Quiz getQuiz;
			for (int l = 0; l < coq; l++)
			{
				fin >> getQuiz.nameQuiz;
				getQuiz.question = new Questions[countOfQuestions[l]];
				if (getQuiz.nameQuiz != "")
				{
					for (int i = 0; i < countOfQuestions[l]; i++)
					{
						fin >> getQuiz.question[i].question1;
						getQuiz.question[i].answer = new Answer[countOfAnswers[l]];
						for (int j = 0; j < countOfAnswers[l]; j++)
						{
							fin >> getQuiz.question[i].answer[j].answer1;
						}
					}
				}
				else
				{
					break;
				}
				insertQuiz(getQuiz);
			}
		}
	}
	fin.close();
} 

void addQuiz()
{
	ofstream fout;
	fout.open("Quiz.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		int *tempCountOfQuestions = new int[countQuiz + 1];
		int *tempCountOfAnswers = new int[countQuiz + 1];
		Quiz *temp = new Quiz[countQuiz + 1];
		for (int i = 0; i < countQuiz; i++)
		{
			temp[i] = quiz[i];
		}
		for (int i = 0; i < countQuiz; i++)
		{
			tempCountOfQuestions[i] = countOfQuestions[i];
		}
		for (int i = 0; i < countQuiz; i++)
		{
			tempCountOfAnswers[i] = countOfAnswers[i];
		}
		cout << "Enter name of new quiz" << endl;
		addNameQuiz(temp);

		cout << "Enter number of questions" << endl;
		cin >> tempCountOfQuestions[countQuiz];
		//------------------------------------------------------------------------------------------------------------------------------------------------
		ofstream fout2;
		fout2.open("Data.txt", fstream::app);
		bool isOpenn = fout.is_open();
		if (isOpenn == true)
		{
			//--------------------------------------------------------------------------------------------------------------------------------------------
			temp[countQuiz].question = new Questions[tempCountOfQuestions[countQuiz]];
			cout << "Enter questions" << endl;
			for (int i = 0; i < tempCountOfQuestions[countQuiz]; i++) // цикл для заповнення питань та відповідей
			{
				cout << "enter " << i + 1 << " question" << endl;
				cin >> temp[countQuiz].question[i].question1;
				cout << "Enter count of enswers" << endl;
				cin >> tempCountOfAnswers[countQuiz];
				temp[countQuiz].question[i].answer = new Answer[tempCountOfAnswers[countQuiz]];
				for (int j = 0; j < tempCountOfAnswers[countQuiz]; j++)
				{
					cout << "Enter " << j + 1 << " answer" << endl;
					cin >> temp[countQuiz].question[i].answer[j].answer1;
				}
			}
			//cout << temp[countQuiz].nameQuiz << endl;// запис у файл
			//for (int i = 0; i < newCountOfQuestions[coq]; i++)
			//{
			//	cout << temp[countQuiz].question[i].question1 << endl;
			//	for (int j = 0; j < newCountOfAnswers[coa]; j++)
			//	{
			//		cout << temp[countQuiz].answer[j].answer1 << endl;
			//	}
			//}

			fout2 << tempCountOfQuestions[countQuiz] << endl;
			fout2 << tempCountOfAnswers[countQuiz] << endl;


			fout << temp[countQuiz].nameQuiz << endl;// запис у файл
			for (int i = 0; i < tempCountOfQuestions[countQuiz]; i++)
			{
				fout << temp[countQuiz].question[i].question1 << endl;
				for (int j = 0; j < tempCountOfAnswers[countQuiz]; j++)
				{
					fout << temp[countQuiz].question[i].answer[j].answer1 << endl;
				}
			}

			fout.close();
			fout2.close();
			coq++;
			coa++;
			countQuiz++;
			delete[] countOfQuestions;
			delete[] countOfAnswers;
			delete[] quiz;
			countOfQuestions = tempCountOfQuestions;
			countOfAnswers = tempCountOfAnswers;
			quiz = temp;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	else
	{
		cout << "Error" << endl;
	}
	CLEAR
}

void listOfQuiz()
{
	for (int i = 0; i < coq; i++)
	{
		cout << quiz[i].nameQuiz << "\t";
	}
	cout << endl;
}

void passTheQuiz()
{
	cout << "Sellect quiz" << endl;
	cout << "Quizzes that are available: ";
	for (int i = 0; i < coq; i++)
	{
		cout << i << ") " << quiz[i].nameQuiz << "\t";
	}
	string name;
	string result;
	int countResult = 0;
	cout << "Enter name which quiz you want to pass" << endl;
	cin >> name;
	for (int i = 0; i < countQuiz; i++)
	{
		if (quiz[i].nameQuiz == name)
		{
			for (int j = 0; j < countOfQuestions[i]; j++)
			{
				cout << "Question " << j + 1 << ": " << endl;
				cout << quiz[i].question[j].question1 << endl;
				cout << "Answer options: ";
				for (int k = 0; k < countOfAnswers[i]; k++)
				{
					cout << quiz[i].question[j].answer[k].answer1 << ";\t";
				}
				//cout << quiz[i].question[j].trueAnswer1 << ";\t";
				cout << " Enter result: ";
				cin >> result;
				for (int k = 0; k < countOfAnswers[i]; k++)
				{
					if (result == quiz[i].question[j].answer[k].answer1)
					{
						countResult++;
					}
				}
			}
			cout << "You have " << countResult << " right answer" << endl;
		}
	}
	PAUSE
	CLEAR
}

void addNameQuiz(Quiz *temp)
{
	cin >> temp[countQuiz].nameQuiz;
	for (int i = 0; i < countQuiz; i++)
	{
		if (temp[countQuiz].nameQuiz == quiz[i].nameQuiz)
		{
			cout << "This name already exists, enter another name" << endl;
			addNameQuiz(temp);
		}
	}
	return;
}

void allinfoInArr()
{
	for (int i = 0; i < countQuiz; i++)
	{
		cout << quiz[i].nameQuiz << endl;
		for (int j = 0; j < countOfQuestions[i]; j++)
		{
			cout << quiz[i].question[j].question1 << endl;
			for (int k = 0; k < countOfAnswers[i]; k++)
			{
				cout << quiz[i].question[j].answer[k].answer1 << endl;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < coq; i++)
	{
		cout << countOfQuestions[i] << endl;
	}
	for (int i = 0; i < coq; i++)
	{
		cout << countOfAnswers[i] << endl;
	}
}