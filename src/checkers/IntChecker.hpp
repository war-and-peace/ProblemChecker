#ifndef INTCHECKER_HEADER
#define INTCHECKER_HEADER

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
    std::ifstream file1(this->output_file_name.c_str()), file2(this->validation_file_name.c_str());

    if (!file1.good() || !file2.good()) {
        throw checker::FileErrorException(static_cast<std::string>(output_file_name));
    }
};

bool checker::IntChecker::check() {
    std::ifstream out1, out2;
    out1.open(output_file_name);
    out2.open(validation_file_name);
    int source, target;
    out1 >> source;
    out2 >> target;
    out1.close();
    out2.close();
    if (source != target) {
        return 1;
    } else {
        return 0;
    }
}

#endif /* INTCHECKER_HEADER */