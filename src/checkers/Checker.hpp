#ifndef CHECKER_HEADER
#define CHECKER_HEADER

#include <fstream>
#include <ios>

namespace checker {

class Checker {
   private:
    /* data */

   public:
    virtual bool check() = 0;
    Checker(std::string_view input_file_path, std::string_view output_file_path, std::string_view validation_file_path):
        input_file_path(input_file_path),
        output_file_path(output_file_path),
        validation_file_path(validation_file_path){};
   protected:
    std::string input_file_path;
    std::string output_file_path;
    std::string validation_file_path;
};

class FileErrorException : public std::exception {
   private:
    /* data */
   public:
    explicit FileErrorException(const std::string &file_name) {
        this->message = "Error opening the file: " + file_name;
    };
    virtual ~FileErrorException() throw(){};
    virtual const char *what() const throw() { return this->message.c_str(); }

   protected:
    std::string message;
};

}  // namespace checker

#endif /* CHECKER_HEADER */