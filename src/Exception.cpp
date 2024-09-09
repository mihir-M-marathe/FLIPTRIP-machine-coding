#include "../include/Exception.hpp"

CustomException::CustomException(const std::string& message) : msg(message) {}

const char* CustomException::what() const noexcept {
    return msg.c_str();
}