// Lab411.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int GETCourses() {
	int CoursesCount;
	do {
		cout << "Enter subjects count: ";
		cin >> CoursesCount;
	} while (CoursesCount <= 0);
	return CoursesCount;
}

int **GetGrades(int subjectCount) {
	int** grades = new int*[subjectCount];
	int gradesCountInCourse;
	for (int i = 0; i < subjectCount; i++) {
		do {
			cout << "Enter count of grades and grades: ";
			cin >> gradesCountInCourse;
		} while (gradesCountInCourse > 5 || gradesCountInCourse < 1);
		grades[i] = new int[gradesCountInCourse + 1];
		for (int j = 0; j < gradesCountInCourse; j++) {
			do {
				cin >> grades[i][j];
			} while (grades[i][j] <= 0 || grades[i][j] >= 6);
			grades[i][gradesCountInCourse] = -1;
		}
	}
	return grades;
}

double SumCoursesFinal(int *grades) {
	int gradesCount = 0;
	double gradesSum = 0;
	for (int j = 0; ; j++) {
		if (grades[j] == -1)
			break;
		gradesCount++;
		gradesSum += grades[j];
	}
	return gradesSum / gradesCount;
}

void ShowFinal(int **grades, int subjectsCount) {
	double currentCourseSum, CoursesSum = 0;
	for (int i = 0; i < subjectsCount; i++) {
		currentCourseSum = SumCoursesFinal(grades[i]);
		CoursesSum += currentCourseSum;
		cout.precision(2);
		cout << fixed << "Course " << i + 1 << ": final " << currentCourseSum << ", grades: ";
		for (int j = 0; ; j++) {
			if (grades[i][j] == -1)
				break;
			cout << grades[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "Overall final: " << CoursesSum / subjectsCount << endl;
}

int main()
{
	int coursesC = GETCourses();
	int **grades = GetGrades(coursesC);
	ShowFinal(grades, coursesC);
	return 0;
}