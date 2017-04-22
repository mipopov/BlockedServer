#ifndef _SELECT_H_
#define _SELECT_H_

#include "student.h"
#include <stdexcept>

class Select{
public:
	Select(char namemin, char namemax, int groupmin, int groupmax, int ratingmin, int ratingmax);
	Select(int numberexam, int markmin, int markmax);
	char NameMin();
	char NameMax();
	int GroupMin();
	int GroupMax();
	int RatingMin();
	int RatingMax();
	int exam();
	int MarkMin();
	int MarkMax();
private:
	char namemin_;
	char namemax_;
	int groupmin_;
	int groupmax_;
	int ratmin_;
	int ratmax_;
	int exam_;
	int markmin_;
	int markmax_;
};

#endif
