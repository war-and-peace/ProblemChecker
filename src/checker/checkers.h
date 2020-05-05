//
// Created by abdurasul on 05.05.2020.
//

#ifndef VERDICT_CHECKERS_H
#define VERDICT_CHECKERS_H

#include <string>
#include <string_view>
#include <cmath>

#include "checker_concepts.h"

namespace checkers {

    template<custom_concepts_::trivial T>
    [[nodiscard]] inline bool equal(T a, T b) noexcept {
        return a == b;
    }

    template<custom_concepts_::container T>
    [[nodiscard]] inline bool equal(const T &a, const T &b) noexcept {
        if (a.size() != b.size())return false;
        auto ita = a.begin();
        auto itb = b.begin();

        for (size_t i{}; i < a.size(); i++) {
            if (*ita != *itb) {
                return false;
            }
        }
        return true;
    }

    [[nodiscard]] inline bool equal(::std::string_view a, ::std::string_view b) noexcept {
        return a == b;
    }

    template<custom_concepts_::FloatingPoint T>
    [[nodiscard]] inline bool equal(T a, T b, T precision) noexcept {
        return (fabs(a - b) < fabs(precision));
    }
}

#endif //VERDICT_CHECKERS_H
