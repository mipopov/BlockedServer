#include "update.h"

Update::Update(char first_name[], int first_group, int first_marks[], char update_name[], int update_group, int update_marks[]){
	UpdateFunction(first_name, first_group, first_marks, update_name, update_group, update_marks);
}

Update::Update(char name_first_min, char name_first_max, char update_name[]){
	Updateall(name_first_min, name_first_max, update_name);
}
Update::Update(char  name_min, char name_max, int marks[]){
	if ((name_min >= 'A') && (name_min <= 'Z') && (name_max >= 'A') && (name_max <= 'Z')){
                name_first_min_ = name_min;
                name_first_max_ = name_max;
        }
        else
                throw 10; //std::invalid_argument("Incrorect name, name should begin from capital letter");
	for(int i = 0; i < 30; ++i){
                if ((marks[i] < 6) && (marks[i] > 2))
                        update_marks_[i] = marks[i];
                else{
                        throw 10; //std::invalid_argument("Incorrect marks, please input correct marks, from 3 to 5");
                }
	}
}
Update::Update(int first_group_min, int first_group_max, int update_group){
	if ((first_group_min < 701) && (first_group_min > 99))
                group_first_min_ = first_group_min;
        else
                throw 10; //std::invalid_argument("Incorrect group, please input group from 100 to 600 ");
	if ((first_group_max < 701) && (first_group_max > 99))
                group_first_max_ = first_group_max;
        else
                throw 10; //std::invalid_argument("Incorrect group, please input group from 100 to 600 ");
	if ((update_group < 701) && (update_group > 99))
                update_group_ = update_group;
        else
                throw 10; //std::invalid_argument("Incorrect group, please input group from 100 to 600 ");
}
void Update::Updateall(char  name_min, char name_max, char update_name[]){
	if ((name_min >= 'A') && (name_min <= 'Z') && (name_max >= 'A') && (name_max <= 'Z')){
                name_first_min_ = name_min;
                name_first_max_ = name_max;
        }
        else
                throw 10; //std::invalid_argument("Incrorect name, name should begin from capital letter");
	if ((update_name[0] <= 'Z') && (update_name[0] >= 'A')){
                for(size_t i = 0; i < strlen(update_name); ++ i)
                        update_name_[i] = update_name[i];
                for(size_t i = strlen(update_name); i <= 20; ++i)
                        update_name_[i] = ' ';
                update_name_[21] = '\0';
        }
        else
                throw 10; //std::invalid_argument("Incorrect name, please input name,which begin from capital letter");

}
void Update::UpdateFunction(char first_name[], int first_group, int first_marks[], char update_name[], int update_group, int update_marks[]){
	if ((first_name[0] <= 'Z') && (first_name[0] >= 'A')){
		for(size_t i = 0; i < strlen(first_name); ++ i)
			first_name_[i] = first_name[i];
		for(size_t i = strlen(first_name); i <= 20; ++i)
			first_name_[i] = ' ';
		first_name_[21] = '\0';
	}
	else
		throw 10; //std::invalid_argument("Incorrect name, please input name,which begins from capital letter");
	if ((first_group < 701) && (first_group > 99))
		first_group_ = first_group;
	else
		throw 10; //std::invalid_argument("Incorrect group, please input group from 100 to 600 ");
	for(int i = 0; i < 30; ++i){
		if ((first_marks[i] < 6) && (first_marks[i] > 2))
			first_marks_[i] = first_marks[i];
		else{
			throw 10; //std::invalid_argument("Incorrect marks, please input correct marks, from 3 to 5");
		}
	}
	if ((update_name[0] <= 'Z') && (update_name[0] >= 'A')){
                for(size_t i = 0; i < strlen(update_name); ++ i)
                        update_name_[i] = update_name[i];
                for(size_t i = strlen(update_name); i <= 20; ++i)
                        update_name_[i] = ' ';
                update_name_[21] = '\0';
        }
        else
                throw 10; //std::invalid_argument("Incorrect name, please input name,which begin from capital letter");
        if ((update_group < 701) && (update_group > 99))
                update_group_ = update_group;
        else
                throw 10; //std::invalid_argument("Incorrect group, please input group from 100 to 600 ");
        for(int i = 0; i < 30; ++i){
                if ((update_marks[i] < 6) && (update_marks[i] > 2))
                        update_marks_[i] = update_marks[i];
                else{
                        throw 10; //std::invalid_argument("Incorrect marks, please input correct marks, from 3 to 5");
                }
        }
}

char *Update::FirstName() {
        return first_name_;
}

int Update:: FirstGroup() {
        return first_group_;
}

int Update::FirstMarks(int p) {
        if (p < 30 && p >= 0)
                return first_marks_[p];
	else
		return -1;
}

char *Update::UpdateName() {
        return update_name_;
}

int Update::UpdateGroup() {
        return update_group_;
}

int Update::UpdateMarks(int p) {
        if (p < 30 && p >= 0)
                return update_marks_[p];
	else
		return -1;
}

char Update::NameFirstMin(){
	return name_first_min_;
}

char Update::NameFirstMax(){
	return name_first_max_;
}

int Update::GroupFirstMin(){
	return group_first_min_;
}

int Update::GroupFirstMax(){
	return group_first_max_;
}
