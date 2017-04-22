#ifndef _READWRITE_H_
#define _READWRITE_H_

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>


ssize_t readAll(int sd, void *buf, size_t length) {
    char *message = (char *)buf;
    size_t res, alreadyRead;
    for (alreadyRead = 0; length; message += res, alreadyRead += res, length -= res)
        if ((res = read(sd, message, length)) <= 0)
            break;
    return alreadyRead ? alreadyRead : res;
}

ssize_t writeAll(int sd, const void *buf, size_t length) {
    const char *message = (const char *)buf;
    ssize_t res, alreadyWritten;
    for (alreadyWritten = 0; length; message += res, alreadyWritten += res, length -= res)
        if ((res = write(sd, message, length)) <= 0)
            break;
    return alreadyWritten ? alreadyWritten : res;
}

#endif
