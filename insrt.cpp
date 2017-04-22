#include "insrt.h"

insrt::insrt(char name[], int group, int marks[]){
	insrtfunction(name, group, marks);
}

void insrt::insrtfunction(char name[], int group, int marks[]){
	if ((name[0] <= 'Z') && (name[0] >= 'A')){
		for(size_t i = 0; i < strlen(name); ++ i)
			_name[i] = name[i];
		for(size_t i = strlen(name); i <= 20; ++i)
			_name[i] = ' ';
		_name[21] = '\0';
	}
	else
		throw 10; //std::invalid_argument("Incorrect name, please input name,which begin from capital letter");
	if ((group < 701) && (group > 99))
		_group = group;
	else
		throw 10; //std::invalid_argument("Incorrect group, please input group from 100 to 600 ");
	for(int i = 0; i < 30; ++i){
		if ((marks[i] < 6) && (marks[i] > 2))
			_marks[i] = marks[i];
		else{
			throw 10; //std::invalid_argument("Incorrect marks, please input correct marks, from 3 to 5");
		}
	}
}

char *insrt::rtname() {
	return _name;
}

int insrt::rtgroup() {
	return _group;
}

int insrt::rtmarks(int p) {
	if (p < 30 && p >= 0)
		return _marks[p];
	else
		return -1;
} 
