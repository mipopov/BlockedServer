#ifndef _PARSE_H_
#define _PARSE_H_

#include "student.h"
#include "update.h"
#include "select.h"
#include "insrt.h"
#include "del.h"
#include <stdexcept>

class parse {
public:
	parse (int fd);
	void choice(const char *str, int fd);	
	void selectfunction(Select S);
	void selectallfunction(Select s);
	void InsertFunction(insrt ins);
	void DeleteFunction(del del_, int flag);
	void DeleteAllFunction();
	void UpdateFunction(Update up_, int status);
	void SaveFunction(int fd);
	int GetType() const;
	std::vector<student> GetResponse();

private:
	int status_response;
	std::vector<student> all;
	std::vector<student> res;
};


#endif
