//
// Created by abdurasul on 05.05.2020.
//

#ifndef VERDICT_CHECKER_CONCEPTS_H
#define VERDICT_CHECKER_CONCEPTS_H

#include <concepts>
#include <type_traits>

namespace custom_concepts_ {
    template<typename T>
    concept hasBegin = requires(T &a){
        { a.begin() };

    };

    template<typename T>
    concept hasEnd = requires(T &a){
        { a.end() };
    };

    template<typename T>
    concept hasBeginEnd = hasBegin<T> && hasEnd<T>;

    template<typename T>
    concept iteratable = requires(T &a){
        { a.begin()++ };
    };

    template<typename T>
    concept hasSize = requires(T &a){
        { a.size() };
    };

    template<typename T>
    concept container = hasBeginEnd<T> && iteratable<T> && hasSize<T>;

    template<typename T>
    concept trivial = ::std::is_trivial_v<T>;

    template<typename T>
    concept FloatingPoint = ::std::is_floating_point_v<T>;
}

#endif //VERDICT_CHECKER_CONCEPTS_H
