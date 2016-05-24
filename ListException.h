#include <exception>
#include <string>

class ListException: public std::exception {
    public:
        ListException(std::string message = "") : message(message) {}
        virtual const char* what() const throw() {
            return this->message.c_str();
        }

    private:
        std::string message;
};
