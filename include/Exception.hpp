#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

class CustomException : public std::exception {

private:
    std::string msg;

public:
    explicit CustomException(const std::string& message);
    virtual const char* what() const noexcept override;
};

#endif