#ifndef _UPDATE_H_
#define _UPDATE_H_

#include"student.h"

class Update {
public:
        Update(char first_name[], int first_group, int first_marks[],char update_name[], int update_group, int update_marks[]);
	Update(char name_min, char name_max, char update_name[]);
	Update(int group_first_min, int group_first_max, int group_max);
	Update(char  name_min, char name_max, int marks[]);
	void UpdateFunction(char first_name[], int first_group, int first_marks[],char update_name[], int update_group, int update_marks[]);
	void Updateall(char  name_min, char name_max, char update_name[]);
	char NameFirstMin();
	char NameFirstMax();
	int GroupFirstMin();
	int GroupFirstMax();
	char *FirstName();
	int FirstGroup();
	int FirstMarks(int p);
	char *UpdateName();
	int UpdateGroup();
	int UpdateMarks(int p);
private:
	char name_first_min_;
	char name_first_max_;
	int group_first_min_;
	int group_first_max_;
	char first_name_[22];
	int first_group_;
	int first_marks_[30];
	char update_name_[22];
        int update_group_;
        int update_marks_[30];
};

#endif
