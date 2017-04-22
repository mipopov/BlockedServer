#include "student.h"

int main(int argc, char ** argv){
	if (argc != 2){
		std::cout << "Error, in input parameters" << std::endl;
		return -1;
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1){
		std::cout << "Error, in open read.cpp file" << std::endl;
	}
	try{
		for(;;){
			student S;
			int r = S.readBin(fd);
			if (r == 0)
				break;
			if (r == -1)
				throw(std::invalid_argument("Error in read"));
			S.writeTXT();
			
		}
	}
	catch(const std::exception &err){
		std::cout << "Exception " << err.what() << std::endl;
	}
	if (close(fd) == -1){
		std::cout << "Error in closing file" << std::endl;
		return -1;
	}
	return 0;
}
