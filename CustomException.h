#ifndef CUSTOMEXCEPTION_H_
#define CUSTOMEXCEPTION_H_

#include <exception>
#include <string>

class CustomException: public std::exception {
    public:
        CustomException(std::string message = "") : message(message) {}
        virtual const char* what() const throw() {
            return this->message.c_str();
        }

    private:
        std::string message;
};

#endif /* CUSTOMEXCEPTION_H_ */
