//
// Created by m3taprog on 13/08/18.
//

#ifndef MATRIXABSFACTORY_MATRIXEXCEPTION_H
#define MATRIXABSFACTORY_MATRIXEXCEPTION_H

#include "headers.h"

class MatrixException : public std::exception{
public:
    MatrixException(std::string const& message) : _message(message + " Exception was thrown.") {}
    virtual ~MatrixException() noexcept {}
    const char* what() const noexcept {
        return _message.c_str();
    }
private:
    std::string _message;
};


#endif //MATRIXABSFACTORY_MATRIXEXCEPTION_H
