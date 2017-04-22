#include "select.h"

Select::Select(char namemin, char namemax, int groupmin, int groupmax, int ratingmin, int ratingmax){
	if ((namemin >= 'A') && (namemin <= 'Z') && (namemax >= 'A') && (namemax <= 'Z')){
		namemin_ = namemin;
		namemax_ = namemax;
	}
	else
		throw 10; std::invalid_argument("Incrorect name, name should begin from capital letter");
	if ((groupmin < 701) && (groupmin > 99) && (groupmax < 701) && (groupmax > 99)){
		groupmin_ = groupmin;
		groupmax_ = groupmax;
	}
	else
		throw 10; //std::invalid_argument("Incorrect group, group should be from 100 to 600");
	if ((ratingmin < 6) && (ratingmax > 2) && (ratingmin > 2) && (ratingmax < 6)){
		ratmin_= ratingmin;
		ratmax_ = ratingmax;
	}
	else
		throw 10; //std::invalid_argument("Incorrect rating, rating should be from 3 to 5");
}

Select::Select(int numberexam, int markmin, int markmax){
	if ((numberexam > 0) && (numberexam < 31))
		exam_ = numberexam;
	else
		throw 10; //std::invalid_argument("Incorrect number of exam, number of exam should be from 1 to 30");
	if ((markmin < 6) && (markmin > 2) && (markmax < 6) && (markmax > 2)){
		markmin_ = markmin;
		markmax_ = markmax;
	}
	else
		throw 10; //std::invalid_argument("Incorrect marks, marks should be from 3 to 5");
}

char Select::NameMin(){
	return namemin_;
}

char Select::NameMax(){
	return namemax_;
}
int Select::GroupMin(){
	return groupmin_;
}
int Select::GroupMax(){
	return groupmax_;
}
int Select::RatingMin(){
	return ratmin_;
}
int Select::RatingMax(){
	return ratmax_;
}
int Select::exam(){
	return exam_;
}
int Select::MarkMin(){
	return markmin_;
}
int Select::MarkMax(){
	return markmax_;
}
