#include "student.h"

student::student(){
        memcpy(name_, "Victor", 6);
	name_[6] = '\0';
  	group_ = 5;
	for(int i = 0; i < 30; ++i)
        	marks_[i] = 5;
}

void student::NameChange(char name[]){
	memcpy(name_, name, strlen(name));
	name_[strlen(name)] = '\0';
}

void student::GroupChange(int group){
	group_ = group;
}

void student::MarksChange(int marks[]){
	for(int i = 0; i < 30; ++i)
		marks_[i] = marks[i];
}

student::student(char name[], int group, int marks[]){
	memcpy(name_, name, strlen(name));
	name_[strlen(name)] = '\0';
	group_ = group;
	for(int i = 0; i < 30; ++i)
		marks_[i] = marks[i];
}

void student::SetRand(){
	int lenname = rand() % 14 + 2;
	name_[0] = 'A' + rand() % 26;
	for(int i = 1; i < lenname; ++i)
		name_[i] = 'a' + rand() % 26; 
	for(int i = lenname; i <= 20; ++i)
		name_[i] = ' ';
	name_[21] = '\0';
	group_ = (rand() % 6 + 1)*100 + rand() % 13 + 1 ;
	for(int i = 0; i < 30; ++i)
		marks_[i] = rand() % 3 + 3;
}

int student::writeBin(int fd){
	if (write(fd, name_, 21) != 21){
		std::cout <<"Error in writeBin: name " << std::endl;
		return -1;
	}
	if (write(fd, &group_, sizeof(group_)) != sizeof(group_)){
                std::cout << "Error in writeBin: group " << std::endl;
                return -1;
        }
	for(int i = 0; i < 30; ++i){
		if (write(fd, &marks_[i], sizeof(marks_[i])) != sizeof(marks_[i])){
                	std::cout << "Error in writeBin: marks " << std::endl;
               	 	return -1;
        	}
	}
	return 1;
}

void student::writeTXT(){
	std::cout << name_ << " " << group_ << " ";
	for(int i = 0; i < 30; ++i){
		std::cout << marks_[i];
	}
	std::cout << std::endl;
}

int student::readBin(int fd){
	int a;
	if ((a = read(fd, name_, 21)) != 21){
		if (a == 0)
			return 0;
		else
			return -1;
	}
	if (read(fd, &group_, sizeof(int)) != sizeof(int))
			return -1;
	for (int i = 0; i < 30; ++i){
		if (read(fd,&marks_[i], sizeof(int)) != sizeof(int))
				return -1;
	} 
	return 1;
}

int student::marks(int i) {
	if (i < 30 && i >= 0)
		return marks_[i];
	else
		return -1;
}
int student::group() {
	return group_;
}
char *student::name() {
	return name_;
}
