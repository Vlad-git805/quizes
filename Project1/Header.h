#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

#define PAUSE system("pause");
#define CLEAR system("cls");

struct Answer
{
	string answer1;
};

struct Questions
{
	string question1;
	string trueAnswer;
	Answer *answer;
};

struct Quiz
{
	string nameQuiz;
	Questions *question;
};

void init2();
void init();
void addQuiz();
void listOfQuiz();
void passTheQuiz();
void addNameQuiz(Quiz *temp);
void allinfoInArr();
void insertQuiz(Quiz quizz);