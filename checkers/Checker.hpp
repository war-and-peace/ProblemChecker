#include <string>
#include <fstream>
#include <ios>

namespace checker{

    class Checker{
    private:
        /* data */

    public:
        // Checker(std::string& output_file_name, std::string& validation_file_name): 
        //     output_file_name(output_file_name), validation_file_name(validation_file_name){};

        virtual bool check() = 0;
    };

    class FileErrorException : public std::exception{
    private:
        /* data */
    public:
        explicit FileErrorException(const std::string& file_name){
            this->message = "Error opening the file: " + file_name;
        };
        virtual ~FileErrorException() throw();
        virtual const char* what() const throw(){
            return this->message.c_str();
        }
    
    protected:
        std::string message;
    };

}