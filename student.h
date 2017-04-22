#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<unistd.h>
#include<stdexcept>
#include<fcntl.h>
#include<vector>

class student{
public:
	student();
	student(char name[], int group, int marks[]);
	void GroupChange(int group);
	void MarksChange(int marks[]);
	void NameChange(char name[]);
	void SetRand();
	int readBin(int fd);
	int writeBin(int fd);
	void writeTXT();
	char* name();
	int group();
	int marks(int i);
	
private:
	char name_[22];
	int group_;
	int marks_[30];
};
#endif
