#include "Checker.hpp"

namespace checker{

    class IntChecker : public Checker{
    private:
        std::string output_file_name;
        std::string validation_file_name;

    public:
        IntChecker(std::string& output_file_name, std::string& validation_file_name);
        ~IntChecker();
        bool check();
    };

}

checker::IntChecker::IntChecker(std::string& output_file_name, std::string& validation_file_name) : 
        output_file_name(output_file_name), validation_file_name(validation_file_name) {
            std::ifstream file1(output_file_name), file2(validation_file_name);
            if (!file1.good() || !file2.good()){
                throw checker::FileErrorException(output_file_name);
            }
        };

bool checker::IntChecker::check(){
    std::ifstream out1, out2;
    out1.open(output_file_name);
    out2.open(validation_file_name);
    int source, target;
    out1 >> source;
    out2 >> target;
    out1.close();
    out2.close();
    if (source != target){
        return 1;
    }else{
        return 0;
    }

}