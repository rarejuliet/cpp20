#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>

struct NotImplementedException : private std::exception {
	explicit NotImplementedException(const char* str) : std::exception(str){}
};

#endif