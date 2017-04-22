#include"student.h"
#include<ctime>

int main(int argc, char **argv){
	srand(0);
	if(argc != 3) {
		std::cout<< "Error in input" << std::endl;
		return -1;
	}
	int fd = open(argv[1], 577, 384);
	if (fd == -1){
		std::cout << "Error in opening file " << std::endl;
		return -1;
	}
	srand(time(NULL));
	try{
		student *S = new student[atoi(argv[2])];
		for(int i = 0; i < atoi(argv[2]); ++i){
			S[i].SetRand();
			S[i].writeBin(fd);
		}
		if(close(fd) == -1){
			std::cout << "Error in close file" << std::endl;
		}
		delete[]S;
	}
	catch(const std::exception &err){
		std::cout<< " Exception message: " << err.what() << std::endl;
		return -1;
	}
	return 0;
}
