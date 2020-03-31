#ifndef INTCHECKER_HEADER
#define INTCHECKER_HEADER

#include <iostream>
#include <string_view>

#include "Checker.hpp"

namespace checker {

class IntChecker : public Checker {
   private:
    std::string output_file_name;
    std::string validation_file_name;

   public:
    IntChecker(std::string_view output_file_name,
               std::string_view validation_file_name);
    ~IntChecker() = default;
    bool check();
};

}  // namespace checker

checker::IntChecker::IntChecker(std::string_view output_file_name,
                                std::string_view validation_file_name)
    : output_file_name(output_file_name),
      validation_file_name(validation_file_name) {
    std::ifstream file1(this->output_file_name), file2(this->validation_file_name);

    if (!file1.good() || !file2.good()) {
        throw checker::FileErrorException(static_cast<std::string>(output_file_name));
    }
};

bool checker::IntChecker::check() {
    std::ifstream out1, out2;
    out1.open(output_file_name);
    out2.open(validation_file_name);
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