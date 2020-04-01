#ifndef INTCHECKER_HEADER
#define INTCHECKER_HEADER

#include <iostream>
#include <string_view>

#include "Checker.hpp"

namespace checker {

class IntChecker : public Checker {
   private:
   public:
    IntChecker(std::string_view input_file_path,
               std::string_view output_file_name,
               std::string_view validation_file_name);
    ~IntChecker() = default;
    bool check();
};

}  // namespace checker

checker::IntChecker::IntChecker(std::string_view input_file_path,
                                std::string_view output_file_path,
                                std::string_view validation_file_path)
    : checker::Checker(input_file_path, output_file_path, validation_file_path) {};

bool checker::IntChecker::check() {
    std::ifstream out1, out2;
    out1.open(this->output_file_path);
    out2.open(this->validation_file_path);
    if (!out1.good() || !out2.good()) {
        throw checker::FileErrorException(static_cast<std::string>(output_file_path));
    }
    int source, target;
    if (!(out1 >> source)) {
        return false;
    }
    if (!(out2 >> target)) {
        return false;
    }
    out1.close();
    out2.close();
    if (source != target) {
        return false;
    } else {
        return true;
    }
}

#endif /* INTCHECKER_HEADER */