#include "parse.h"

std::vector<char> skip(const char *txt) {
	std::vector<char> v;
	for(size_t i = 0; i < strlen(txt); ++i){
		if (!isblank(txt[i]))
			v.push_back(txt[i]);
	}
	return v;
}

parse::parse(int fd) {
	status_response = 7;
	lseek(fd, 0, SEEK_SET);
	all.clear();
	for(;;){
		student S;
		int r = S.readBin(fd);
		if (r == 0) 
			break;
		if (r == -1)
			throw std::invalid_argument("Error in read");
		all.push_back(S);
	}
}

void parse::choice(const char *s, int fd) {
	char name_filter_min, name_filter_max;
	int group_filter_min, group_filter_max, rating_filter_min, rating_filter_max, exam, mark_min, mark_max;
	std::vector<char> str;
	str = skip(s);
	status_response = 7;
	int x = 0, k = 0, p = 0, l = 0;
	if (sscanf(&str[0], "selectname=[%c,%c]group=[%d,%d]rating=[%d,%d]%n", 
			&name_filter_min, 
			&name_filter_max, 
			&group_filter_min, 
			&group_filter_max, 
			&rating_filter_min, 
			&rating_filter_max, 
			&x) == 6) {
		if (x == 43){
			selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
			status_response = 1;
			return;
		}
	}
	if (sscanf(&str[0], "selectname=[%c,%c]group=[%d,%d]%n",
                        &name_filter_min,
                        &name_filter_max,
                        &group_filter_min,
                        &group_filter_max,
                        &x) == 4) {
                if (x == 31){
                        rating_filter_min = 3;
                        rating_filter_max = 5;
                        selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
                        status_response = 1;
                        return;
		}
        }
	if (sscanf(&str[0], "selectname=[%c,%c]rating=[%d,%d]%n",
                        &name_filter_min,
                        &name_filter_max,
                        &rating_filter_min,
                        &rating_filter_max,
                        &x) == 4){
              	if (x == 28){
                	group_filter_min = 100;
                	group_filter_max = 699;
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
			status_response = 1;
                	return;
		}
        }

	if (sscanf(&str[0], "selectname=[%c,%c]%n", 
			&name_filter_min, 
			&name_filter_max, 
			&x) == 2){
		if (x == 16){
			group_filter_min = 100;
			group_filter_max = 699;
			rating_filter_min = 3;
			rating_filter_max = 5;
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
			status_response = 1;
                	return;
		}
        }
	if (sscanf(&str[0], "selectgroup=[%d,%d]name=[%c,%c]rating=[%d,%d]%n", 
			&group_filter_min, 
			&group_filter_max, 
			&name_filter_min, 
			&name_filter_max, 
			&rating_filter_min, 
			&rating_filter_max, 
			&x) == 6){
		if (x == 43){
			status_response = 1;
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
                	return;
		}
        }
	if (sscanf(&str[0], "selectgroup=[%d,%d]name=[%c,%c]%n",
                        &group_filter_min, 
                        &group_filter_max,
                        &name_filter_min,
                        &name_filter_max,
                        &x) == 4) {
		if (x == 31) {
                	rating_filter_min = 3;
                	rating_filter_max = 5;
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
			status_response = 1;
                	return;
		}
        }
        if (sscanf(&str[0], "selectgroup=[%d,%d]rating=[%d,%d]%n",
                        &group_filter_min, 
                        &group_filter_max,
                        &rating_filter_min,
                        &rating_filter_max,
                        &x) == 4){
		if (x == 33){
                	name_filter_min = 'A';
                	name_filter_max = 'Z';
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
			status_response = 1;
                	return;
		}
        }
	if (sscanf(&str[0], "selectgroup=[%d,%d]%n",
                	&group_filter_min,
                	&group_filter_max,
                	&x) == 2){
		if (x == 21){
			name_filter_min = 'A';
			name_filter_max = 'Z';
			rating_filter_min = 3;
			rating_filter_max = 5;
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
			status_response = 1;
                	return;
		}
        }	

	if (sscanf(&str[0], "selectrating=[%d,%d]name=[%c,%c]group=[%d,%d]%n",
                        &rating_filter_min,
                        &rating_filter_max,
                        &name_filter_min,
                        &name_filter_max,
                        &group_filter_min,
                        &group_filter_max,
                        &x) == 6){
		if (x == 43){
			status_response = 1;
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
                	return;
		}
        }
	if (sscanf(&str[0], "selectrating=[%d,%d]name=[%c,%c]%n",
                        &rating_filter_min,
                        &rating_filter_max,
                        &name_filter_min,
                        &name_filter_max,
                        &x) == 4) {
		if (x == 33){
                	group_filter_min = 100;
                	group_filter_max = 699;
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
			status_response = 1;
                	return;
		}
        }
        if (sscanf(&str[0], "selectrating=[%d,%d]group=[%d,%d]%n",
                        &rating_filter_min,
                        &rating_filter_max,
                        &group_filter_min,
                        &group_filter_max,
                        &x) == 4){
		if (x == 28) {
                	name_filter_min = 'A';
                	name_filter_max = 'Z';
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
			status_response = 1;
                	return;
		}
        }
        if (sscanf(&str[0], "selectrating=[%d,%d]%n",
                        &rating_filter_min,
                        &rating_filter_max,
                        &x) == 2){
		if (x == 18){
                	name_filter_min = 'A';
                	name_filter_max = 'Z';
                	group_filter_min = 100;
                	group_filter_max = 699;
                	selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
			status_response = 1;
                	return;
		}
        }
	if (sscanf(&str[0], "selectallexam=%dmark=[%d,%d]%n",
				&exam,
				&mark_min,
				&mark_max,
				&x) == 3){
		if (x == 25){
			selectallfunction(Select(exam, mark_min, mark_max));
			status_response = 1;
			return;
		}
	}
	if (sscanf(&str[0], "selectallmark=[%d,%d]exam=%d%n",
                                &mark_min,
                                &mark_max,
				&exam,
                                &x) == 3){
		if (x == 25){
                	selectallfunction(Select(exam, mark_min, mark_max));
			status_response = 1;
                	return;
		}
        }
	//INSERT
	char name_insert[64];
	int group_insert;
	int marks_insert[30];
	sscanf(&str[0],"insertname=%n", &x);
	if (x == 11){
		while (sscanf(&str[k + x], "group=%dmarks=%n", &group_insert, &p) != 1) {
			name_insert[k] = str[k + x];
			++k;
		}
		name_insert[k] = '\0';
		for (int i = k + x + p; i < k + x + p + 30; ++i){
			sscanf(&str[i], "%1d", &marks_insert[i - k - x - p]);
		}
		InsertFunction(insrt(name_insert, group_insert, marks_insert));
		return;
	}
	//DELETE
	int flag = 0; 
	char name_delete[64];
	int group_delete;
	int marks_delete[30];
	x = 0; k = 0;
	char name_delete_min, name_delete_max;
        int group_delete_min, group_delete_max, rating_delete_min, rating_delete_max;	
	if (sscanf(&str[0], "deletename=[%c,%c]group=[%d,%d]rating=[%d,%d]%n",
                        &name_delete_min,
                        &name_delete_max,
                        &group_delete_min,
       			&group_delete_max,
			&rating_delete_min,
			&rating_delete_max,
			&x) == 6) {
		if (x == 43){
			flag = 5;
			DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
			return;
		}
	}
	if (sscanf(&str[0], "deletename=[%c,%c]rating=[%d,%d]group=[%d,%d]%n", 
			&name_delete_min, 	
			&name_delete_max, 
			&rating_delete_min, 
			&rating_delete_max, 
			&group_delete_min, 
			&group_delete_max, 
			&x) == 6) {
		if (x == 43) {
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
	if (sscanf(&str[0], "deletename=[%c,%c]%n", 
			&name_delete_min, 
			&name_delete_max, 
			&x) == 2){
		if (x == 16){
			group_delete_min = 100;
			group_delete_max = 699;
			rating_delete_min = 3;
			rating_delete_max = 5;
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
	if (sscanf(&str[0], "deletename=[%c,%c]group=[%d,%d]%n", 
			&name_delete_min, 
			&name_delete_max, 
			&group_delete_min, 
			&group_delete_max, 
			&x) == 4) {
		if (x == 31){
			rating_delete_min = 3;
			rating_delete_max = 5;
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
	if (sscanf(&str[0], "deletename=[%c,%c]rating=[%d,%d]%n", 
			&name_delete_min, 
			&name_delete_max, 
			&rating_delete_min, 
			&rating_delete_max, 
			&x) == 4){
		if (x == 28) {
                	group_delete_min = 100;
                	group_delete_max = 699;
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
	 if (sscanf(&str[0], "deletegroup=[%d,%d]name=[%c,%c]rating=[%d,%d]%n", 
			&group_delete_min, 
			&group_delete_max, 
			&name_delete_min, 
			&name_delete_max, 
			&rating_delete_min, 
			&rating_delete_max, 
			&x) == 6){
		if (x == 43) {
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
	if (sscanf(&str[0], "deletegroup=[%d,%d]rating=[%d,%d]name=[%c,%c]%n", 
			&group_delete_min, 
			&group_delete_max, 
			&rating_delete_min, 
			&rating_delete_max, 
			&name_delete_min, 
			&name_delete_max, 
			&x) == 6){
		if (x == 43) {
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
	if (sscanf(&str[0], "deletegroup=[%d,%d]%n",
                	&group_delete_min,
                	&group_delete_max,
                	&x) == 2){
		if (x == 21) {
			name_delete_min = 'A';
			name_delete_max = 'Z';
			rating_delete_min = 3;
			rating_delete_max = 5;
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }	
	if (sscanf(&str[0], "deletegroup=[%d,%d]name=[%c,%c]%n",
                	&group_delete_min, 
			&group_delete_max,
                	&name_delete_min,
                	&name_delete_max,
                	&x) == 4) {
		if (x == 31) {
			rating_delete_min = 3;
			rating_delete_max = 5;
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
	}
	if (sscanf(&str[0], "deletegroup=[%d,%d]rating=[%d,%d]%n",
                	&group_delete_min, 
			&group_delete_max,
                	&rating_delete_min,
                	&rating_delete_max,
                	&x) == 4){
		if (x == 33) {
			name_delete_min = 'A';
			name_delete_max = 'Z';
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
	}

	if (sscanf(&str[0], "deleterating=[%d,%d]name=[%c,%c]group=[%d,%d]%n",
                        &rating_delete_min,
                        &rating_delete_max,
                        &name_delete_min,
                        &name_delete_max,
                        &group_delete_min,
                        &group_delete_max,
                        &x) == 6){
		if (x == 43) {
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
        if (sscanf(&str[0], "deleterating=[%d,%d]group=[%d,%d]name=[%c,%c]%n",
                        &rating_delete_min,
                        &rating_delete_max,
                        &group_delete_min,
                        &group_delete_max,
                        &name_delete_min,
                        &name_delete_max,
                        &x) == 6){
		if (x == 43) {
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
        if (sscanf(&str[0], "deleterating=[%d,%d]%n",
                        &rating_delete_min,
                        &rating_delete_max,
                        &x) == 2){
		if (x == 18) {
                	name_delete_min = 'A';
                	name_delete_max = 'Z';
                	group_delete_min = 100;
                	group_delete_max = 699;
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
        if (sscanf(&str[0], "deleterating=[%d,%d]name=[%c,%c]%n",
                        &rating_delete_min,
                        &rating_delete_max,
                        &name_delete_min,
                        &name_delete_max,
                        &x) == 4) {
		if (x == 33) {
                	group_delete_min = 100;
                	group_delete_max = 699;
			flag = 5;
                	DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
        }
        if (sscanf(&str[0], "deleterating=[%d,%d]group=[%d,%d]%n",
                        &rating_delete_min,
                        &rating_delete_max,
                        &group_delete_min,
                        &group_delete_max,
                        &x) == 4){
		if (x == 28) {
                	name_delete_min = 'A';
			name_delete_max = 'Z';
			flag = 5;
			DeleteFunction(del(name_delete_min, name_delete_max, group_delete_min, group_delete_max, rating_delete_min, rating_delete_max), flag);
                	return;
		}
	}
	p = 0;
	sscanf(&str[0], "deletename=%n", &x);
	if (x == 11) {
		while (sscanf(&str[k + x], "group=%dmarks=%n", &group_delete, &p) != 1) {
                	name_delete[k] = str[k + x];
                	++k;
        	}
        	name_delete[k] = '\0';
		std::cout << name_delete << group_delete;
        	for (int i = k + x + p; i < k + x + p + 30; ++i){
                	sscanf(&str[i], "%1d", &marks_delete[i - k - x - p]);
        	}
		flag = 1;
        	DeleteFunction(del(name_delete, group_delete, marks_delete), flag);
		return;
	}
	
	if (sscanf(&str[0], "deletegroup=%d%n", &group_delete, &x)){
		flag = 2;
		DeleteFunction(del(group_delete), flag);
		return;
	}
	sscanf(&str[0], "deletemarks=%n", &x);
	if (x == 12) {
		for(int i = x; i < x + 30; ++i){
			sscanf(&str[i], "%1d",  &marks_delete[i - x]);
		}
		flag = 3;
		DeleteFunction(del(marks_delete), flag);
		return;
	}
	sscanf(&str[0], "Deletename=%n", &x);
	if (x == 11) {
		int n = 0;
		sscanf(&str[x], "%s%n", name_delete, &n);
		flag = 4;
		DeleteFunction(del(name_delete), flag);
		return;
	}
// UPDATE
	char name_first[64];
	char name_update[64];
	int group_first;
	int group_first_min;
	int group_first_max;
	int group_update;
	int marks_first[30];
	int marks_update[30];
	k = 0; 
	x = 0;
	p = 0;
	int m = 0;
	int fl = 0;
	char name_first_min, name_first_max;
	if (sscanf(&str[0], "updatename=[%c,%c]ONname=%21s%n", &name_first_min, &name_first_max, name_update, &x) == 3){
                fl = 2;
		name_update[21] = '\0';
                UpdateFunction(Update(name_first_min, name_first_max, name_update), fl);
                return;
        }

	if (sscanf(&str[0], "updategroup=[%d,%d]ONgroup=%d", &group_first_min, &group_first_max, &group_update) == 3){
                fl = 3;
                UpdateFunction(Update(group_first_min, group_first_max, group_update), fl);
                return;
        }
	if (sscanf(&str[0], "updatename=[%c,%c]ONmarks=%n", &name_first_min, &name_first_max,&x)){
		for(int i = 0; i < 30; ++i)
			sscanf(&str[i + x], "%1d", &marks_update[i]);
		fl = 12;
		UpdateFunction(Update(name_first_min, name_first_max, marks_update), fl);
		return;
	}
	p = 0;
	sscanf(&str[0], "updatename=%n", &x);
        if (x == 11) {
                while (sscanf(&str[k + x], "group=%dmarks=%n", &group_first, &p) != 1) {
                        name_first[k] = str[k + x];
                        ++k;
                }
        	name_first[k] = '\0';
		for (int i = k + x + p; i < k + x + p + 30; ++i){
                        sscanf(&str[i], "%1d", &marks_first[i - k - x - p]);
                }
		if (str[k + x + p + 30] == 'O') {
			int l = k + x + p + 30;
			sscanf(&str[l], "ONname=%n", &p);
			if (p == 7){
				while (sscanf(&str[m + l + p], "group=%dmarks=", &group_update) != 1) {
					name_update[m] = str[m + l + p];
					++m; 
				}
				name_update[m] = '\0';
		 		for (int i = m + l + p + 15; i < m + l + p + 45; ++i){
                        		sscanf(&str[i], "%1d", &marks_update[i - m - l - p - 15]);
               			}
			}
		}
		else
			throw 10; //std::invalid_argument("Error, perhaps you input so many marks, .........");
		fl = 1;
                UpdateFunction(Update(name_first, group_first, marks_first, name_update, group_update, marks_update), fl);
                return;
	}
	sscanf(&str[0], "selectall%n", &x);
	if (x == 9){
                name_filter_min = 'A';
                name_filter_max = 'Z';
                group_filter_min = 100;
                group_filter_max = 699;
                rating_filter_min = 3;
                rating_filter_max = 5;
                selectfunction(Select(name_filter_min, name_filter_max, group_filter_min, group_filter_max, rating_filter_min, rating_filter_max));
		status_response = 1;
                return;
	}
	sscanf(&str[0], "deleteall%n", &x);
	if (x == 9) {
		DeleteAllFunction();
		return;
	}
	sscanf(&str[0], "save%n", &x);
        if (x == 4){
		SaveFunction(fd);
		return;
        }
	throw 10;
}

void parse::selectfunction(Select sel) {
	res.clear();
	double sum = 0;
	for (size_t i = 0; i < all.size(); ++i){
		for(int j = 0; j < 30; ++j)
			sum += all[i].marks(j);
		int rating_ = sum / 30;
		if (((all[i].name())[0] >= sel.NameMin()) && ((all[i].name())[0] <= sel.NameMax()) && (all[i].group() >= sel.GroupMin()) && (all[i].group() <= sel.GroupMax()) && (rating_ >= sel.RatingMin()) && (rating_ <= sel.RatingMax()))
			res.push_back(all[i]);  
	sum = 0;
	}
}

void parse::selectallfunction(Select s) {
	res.clear();
	for(size_t i = 0; i < all.size(); ++i){
		if ((all[i].marks(s.exam() - 1) >= s.MarkMin()) && (all[i].marks(s.exam() - 1) <= s.MarkMax()))
			res.push_back(all[i]);
	}
}

void parse::InsertFunction(insrt ins) {
	int marks[30];
	for(int i = 0; i < 31; ++i)
		marks[i] = ins.rtmarks(i);
	student S(ins.rtname(), ins.rtgroup(), marks);
	all.push_back(S);
	status_response = 2;
}

void parse::DeleteFunction(del del_, int flag){
	int count_name = 0, count_marks = 0;
	int sum = 0;
	if(flag == 1) {
		for (size_t i = 0; i < all.size(); ++i) {
			for (size_t j = 0; j < strlen(del_.NameFilt()) ; ++j){
				if (all[i].name()[j] != del_.NameFilt()[j])
					break;
				else
					++count_name;
			}
			for (int k = 0; k < 30; ++k){
				if (all[i].marks(k) != del_.MarksFilt(k))
					break;
				else
					++count_marks;
			}
			if (((size_t)count_name == (size_t)strlen(del_.NameFilt())) && (count_marks == 30) && ((size_t)all[i].group() == (size_t) del_.GroupFilt()))
				all.erase(all.begin() + i);
			count_name = 0;
			count_marks = 0;
		}
	}
	
	if (flag == 2) {
		for (size_t i = 0; i < all.size(); ++i) {
			if (all[i].group() == del_.GroupFilt())
				all.erase(all.begin() + i);
		}
	}

	if (flag == 3) {
		for (size_t i = 0; i < all.size(); ++i) {
			for(int k = 0; k < 30; ++k){ 
				if (all[i].marks(k) != del_.MarksFilt(k))
                        		break;
                        	else
                        		++count_marks;
			}
			if ((count_marks == 30))
				all.erase(all.begin() + i);
			count_marks = 0;
		}
	}
	count_name = 0;
	if (flag == 4){
		for (size_t i = 0; i < all.size(); ++i) {
			for (int j = 0; j < 21 ; ++j){
                        	if ((size_t)all[i].name()[j] == (size_t)del_.NameFilt()[j])
                                	++count_name;
                                else
                                        break;
                        }
		if ((size_t)count_name == (size_t)strlen(del_.NameFilt()))
			all.erase(all.begin() + i);
		count_name = 0;
		}
	}
	if (flag == 5){
		for (size_t i = 0; i < all.size(); ++i){
			for(int j = 0; j < 30; ++j)
                        	sum += all[i].marks(j);
                	int rating_ = sum / 30;
			if (((all[i].name())[0] >= del_.NameMin()) && ((all[i].name())[0] <= del_.NameMax()) && (all[i].group() >= del_.GroupMin()) && (all[i].group() <= del_.GroupMax()) && (rating_ >= del_.RatingMin()) && (rating_ <= del_.RatingMax())){
			all.erase(all.begin() + i);
			}
			sum = 0;
		}
	}
	status_response = 3;
}

void parse::UpdateFunction(Update up_, int fl) {
	int count_name = 0;
	int count_marks = 0;
	if (fl == 12){
		int mas[30];
                for(int p = 0; p < 30; ++p)
                        mas[p] = up_.UpdateMarks(p);
		for (size_t i = 0; i < all.size(); ++i){
                        if (((all[i].name())[0] >= up_.NameFirstMin()) && ((all[i].name())[0] <= up_.NameFirstMax())){
                                all[i].MarksChange(mas);
                        }
                }
	}
	if (fl == 1){
		int mas[30];
		for(int p = 0; p < 30; ++p)
			mas[p] = up_.UpdateMarks(p);
		for (size_t i = 0; i < all.size(); ++i) {
        		for (size_t j = 0; j < strlen(up_.FirstName()) ; ++j){
                		if (all[i].name()[j] != up_.FirstName()[j])
                        		break;
                       		else
                       			++count_name;
                	}
			if ((size_t)count_name == (size_t)strlen(up_.FirstName())){
				all[i].NameChange(up_.UpdateName());
			}
           		for (int k = 0; k < 30; ++k) {
                		if (all[i].marks(k) != up_.FirstMarks(k))
                       			break;
                       		else
                       			++count_marks;
                	}
			if (count_marks == 30) {
				all[i].MarksChange(mas);
			}
			if (all[i].group() == up_.FirstGroup()){
				all[i].GroupChange(up_.UpdateGroup());
			}
			count_name = 0;
			count_marks = 0;
		}
	}
	if (fl == 2){
		for (size_t i = 0; i < all.size(); ++i){
                	if (((all[i].name())[0] >= up_.NameFirstMin()) && ((all[i].name())[0] <= up_.NameFirstMax())){
                        	all[i].NameChange(up_.UpdateName());
                        }
                }
	}
	if (fl == 3) {
		for (size_t i = 0; i < all.size(); ++i){
			if ((all[i].group() >= up_.GroupFirstMin()) && (all[i].group() <= up_.GroupFirstMax()))
				all[i].GroupChange(up_.UpdateGroup());
		}
	}
	status_response = 4;
}
void parse::SaveFunction(int fd){
	if (fd) {
        	if (close(fd) == -1)
			throw std::invalid_argument("Can't close file in parse");
                        fd = open("a.db", 577, 384);
                        if (fd == -1)
                                throw std::invalid_argument("Can't open file in parse");
                        for (size_t i = 0; i < all.size(); ++i)
                                all[i].writeBin(fd);
                        status_response = 5;
                        return;
                }
                else
                        throw std::invalid_argument("File is not open");
}

void parse::DeleteAllFunction(){
	all.clear();
	status_response = 3;
}

int parse::GetType() const{
	return status_response;
}

std::vector <student> parse::GetResponse() {
	return res;
}
