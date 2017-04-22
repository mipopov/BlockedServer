#ifndef _DEL_H_
#define _DEL_H_

#include "student.h"

class del{
public:
	del(char name[], int group, int marks[]);
	del(char namemin, char namemax, int groupmin, int groupmax, int ratingmin, int ratingmax);
	del(int group);
	del(char name[]);
	del(int marks[]);
	void delfunction(char name[], int group, int marks[]);
	char *NameFilt();
	int GroupFilt();
	int MarksFilt(int p);
	char NameMin();
	char NameMax();
	int GroupMin();
	int GroupMax();
	int RatingMin();
	int RatingMax();
private:
	char namemax_;
	char namemin_;
	int groupmin_;
	int groupmax_;
	int ratmin_;
	int ratmax_;
	char _name[64];
	int _group;
	int _marks[30];
};

#endif
