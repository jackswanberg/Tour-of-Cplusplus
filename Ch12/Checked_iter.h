#include <exception>

struct Missing_container : std::exception {
    const char* what() const noexcept override { return "Missing container"; }
};

struct Overflow : std::exception {
    const char* what() const noexcept override { return "Iterator overflow"; }
};

template<typename C>
class Checked_iter {
public:
    using value_type = typename C::value_type;
    using difference_type = int;

    Checked_iter() { throw Missing_container{};}
    Checked_iter(C& cc) : pc{&cc} {}
    Checked_iter(C& cc, typename C::iterator pp) : pc{&cc}, p{pp} {}

    Checked_iter& operator++(){check_end(); ++p; return *this; }
    Checked_iter operator++(int) {check_end(); auto t{ *this }; ++p; return t;}
    value_type& operator*() { check_end(); return *p; }

    bool operator==(const Checked_iter& other) const {return p==other.p;}
    bool operator!=(const Checked_iter& other) const {return p!=other.p;}
private:
    void check_end() const {if (p==pc->end()) throw Overflow{}; }
    C* pc{}; // Pointer to the container
    typename C::iterator p = pc->begin();; // Current position in the container
};
