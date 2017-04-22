#include "del.h"

del::del(char name[], int group, int marks[]){
	delfunction(name, group, marks);
}

del::del(char namemin, char namemax, int groupmin, int groupmax, int ratingmin, int ratingmax){
        if ((namemin >= 'A') && (namemin <= 'Z') && (namemax >= 'A') && (namemax <= 'Z')){
                namemin_ = namemin;
                namemax_ = namemax;
        }
        else
                throw 10;//std::invalid_argument("Incrorect name, name should begin from capital letter");
        if ((groupmin < 701) && (groupmin > 99) && (groupmax < 701) && (groupmax > 99)){
                groupmin_ = groupmin;
                groupmax_ = groupmax;
        }
        else
                throw 10;//std::invalid_argument("Incorrect group, group should be from 100 to 600");
        if ((ratingmin < 6) && (ratingmax > 2) && (ratingmin > 2) && (ratingmax < 6)){
                ratmin_= ratingmin;
                ratmax_ = ratingmax;
        }
        else
                throw 10;//std::invalid_argument("Incorrect rating, rating should be from 3 to 5");
}

del:: del(int group) {
	if ((group < 601) && (group > 99))
        	_group = group;
        else
                throw 10; //std::invalid_argument("Incorrect group, please input group from 100 to 600 ");
}
del::del(int marks[]) {
	for (int i = 0; i < 30; ++i)
        	_marks[i] = marks[i];
}
del::del(char name[]){
	if ((name[0] <= 'Z') && (name[0] >= 'A')) {
        	for(size_t i = 0; i < strlen(name); ++ i)
                	_name[i] = name[i];
                for(size_t i = strlen(name); i <= 20; ++i)
                        _name[i] = ' ';
                _name[21] = '\0';
        }
        else
                throw 10; //std::invalid_argument("Incorrect name, please input name,which begin from capital letter");
}
void del::delfunction(char name[], int group, int marks[]){
	if ((name[0] <= 'Z') && (name[0] >= 'A')) {
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
	for (int i = 0; i < 30; ++i)
        	_marks[i] = marks[i];
}

char * del::NameFilt() {
        return _name;
}

int del::GroupFilt() {
        return _group;
}

int del::MarksFilt(int p) {
        if (p < 30 && p >= 0)
                return _marks[p];
	else
		return -1;
}
char del::NameMin(){
        return namemin_;
}

char del::NameMax(){
        return namemax_;
}
int del::GroupMin(){
        return groupmin_;
}
int del::GroupMax(){
        return groupmax_;
}
int del::RatingMin(){
        return ratmin_;
}
int del::RatingMax(){
        return ratmax_;
}
