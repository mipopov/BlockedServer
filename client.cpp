#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include <stdexcept>

#include "ReadWrite.h"


int main(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "You should write port and host" << std::endl;
		return -1;
	}
	char *host = new char[strlen(argv[2]) + 1];
   	memcpy(host, argv[2], strlen(argv[2]));
    	host[strlen(argv[2])] = '\0';
    	struct sockaddr_in addr;
    	int sd; // Socket Descriptor
    	int port = atoi(argv[1]);
    	memset(&addr, 0, sizeof addr);
    	addr.sin_family = AF_INET;
    	addr.sin_port = htons(port);
    	if (inet_pton(AF_INET, host, &addr.sin_addr) < 1) {
        	fprintf(stderr, "Wrong host\n");
        	return -1;
    	}
    	sd = socket(AF_INET, SOCK_STREAM, 0);
    	if (sd == -1) {
        	fprintf(stderr, "Can't create socket\n");
        	return -1;
    	}
    	if (connect(sd, (struct sockaddr *) &addr, sizeof addr) == -1) {
        	fprintf(stderr, "Can't connect to the server\n");
        	if (close(sd))
            		fprintf(stderr, "Can't release file descriptor\n");
        	return -1;
    	}
    	try {
        	char message[1024];
        	for (;;) {
            		std::cout << "Please, input your request\n>>> ";
            		if (fgets(message, 1024, stdin) == 0)
				break;
            		size_t len = strlen(message);
            		message[len - 1] = '\0';
            		if (writeAll(sd, &len, sizeof(len)) != sizeof(len))
               	 		throw std::invalid_argument("Cant write length");
            		if (writeAll(sd, message, len) != (ssize_t) len)
                		throw std::invalid_argument("Cant write message");
            	int status;
            	int quantity;
            	for (size_t i = 0; i < 2; ++i) {
                	size_t length;
                	if (readAll(sd, &length, sizeof(length)) != sizeof(length))
                		throw std::invalid_argument("Can`t read length");
                	std::vector<char> response(length);
                	memset(&response[0], 0, length);
                	if (readAll(sd, &response[0], length) != (ssize_t) length)
                    		throw std::invalid_argument("Can`t read message");
                	if (i == 0)
                    		status = atoi(&response[20]);
                	if (i == 1 && status == 1) {
                    		sscanf(&response[4], "quantity = %d", &quantity);
                    		break;
                	}
                	for (size_t j = 0; j < length; ++j)
                    		std::cout << response[j];
                	std::cout << std::endl;
                	if (status == 7)
                    		break;
            	}
            	if (status == 1) {
                	for (size_t i = 0; i < (size_t)quantity; ++i) {
                    		size_t length;
                    		if (readAll(sd, &length, sizeof(length)) != sizeof(length))
                        		throw std::invalid_argument("Can`t read length");
                    		std::vector<char> response(length);
                    		memset(&response[0], 0, length);
                    		if (readAll(sd, &response[0], length) != (ssize_t) length)
                        		throw std::invalid_argument("Can`t read message");
                    		for (size_t j = 0; j < length; ++j)
                        		std::cout << response[j];
                    			std::cout << std::endl;
                	}
                	std::cout << "\n    Number of your select is: " << quantity << std::endl;
            	}
        	}
    	}
    	catch (std::exception &err) {
        	fprintf(stderr, "Exception:\n   %s", err.what());
    	}
    	if(shutdown(sd, 2) == -1)
        	fprintf(stderr, "Can't shutdown socket\n");

    	if(close(sd)) {
        	fprintf(stderr, "Can't release file descriptor\n");
        	return -1;
    	}
    	delete host;
    	return 0;
}
