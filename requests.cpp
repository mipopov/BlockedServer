#include "parse.h"
#include "student.h"

int main() {
	int fd = open("a.db", O_RDONLY);
	if (fd == -1) {
		std::cout << "Error in open file (requests) " << std::endl;
		return -1;
	}
	parse Req(fd);
	while(true) {
		char request[1024];
		fgets(request, 1024, stdin);
		try {
			Req.choice(request);
		}
		catch(const std::exception &err){
			std::cout << "Exception message: " << err.what() << std::endl;
			return -1;
		}
	}
	if (close(fd) == -1){
		std::cout << "Error in close file (requests) " << std::endl;
		return -1;
	}
}

