#ifndef _INSRT_H_
#define _INSRT_H_

#include "student.h"

class insrt{
public:
        insrt(char name[], int group, int marks[]);
	void insrtfunction(char name[], int group, int marks[]);
	char* rtname();
	int rtgroup();
	int rtmarks(int p);
private:
	int status;
	char _name[64];
	int _group;
	int _marks[30];
};

#endif
