#include <iostream>
#include <concepts>

template <typename T>
concept ComplexConcept = requires(T obj) {
    { obj.hash() } -> std::convertible_to<long>;
    { obj.toString() } -> std::same_as<std::string>;
        requires !std::has_virtual_destructor<T>::value;
};

class ComplexType1 {
public:
    long hash() const {
        return 42;
    }

    std::string toString() const {
        return "ComplexType1";
    }
};

class ComplexType2 {
public:
    long hash() const {
        return 87;
    }

    std::string toString() const {
        return "ComplexType2";
    }

    virtual ~ComplexType2() {}
};

int main() {
    static_assert(ComplexConcept<ComplexType1>);
    //static_assert(ComplexConcept<ComplexType2>); // compilation error
    return 0;
}