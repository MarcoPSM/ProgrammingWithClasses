#include <vector>

namespace mar {

template <class T>
void Write(const std::vector<T> &v, const std::string &separator = " ",
           std::ostream &output = std::cout) {
    for (typename std::vector<T>::const_iterator i = v.begin(); i != v.end();
         i++) {
        output << (i != v.begin() ? separator : "") << *i;
    }
}

template <class T>
void WriteLine(const std::vector<T> &v, const std::string &separator = " ",
               std::ostream &output = std::cout) {
    Write(v, separator, output);
    output << std::endl;
}

template <class T>
void WriteBackwords(const std::vector<T> &v, const std::string &separator = " ",
                    std::ostream &output = std::cout) {
    for (typename std::vector<T>::const_reverse_iterator i = v.rbegin();
         i != v.rend(); i++) {
        output << (i != v.rbegin() ? separator : "") << *i;
    }
}

template <class T>
void WriteBackwordsLine(const std::vector<T> &v,
                        const std::string    &separator = " ",
                        std::ostream         &output    = std::cout) {
    WriteBackwords(v, separator, output);
    output << std::endl;
}

template <class T> unsigned LowerIndex(const std::vector<T> &v, const T &x) {
    return static_cast<unsigned>(std::lower_bound(v.begin(), v.end(), x) -
                                 v.begin());
}

template <class T> unsigned UpperIndex(const std::vector<T> &v, const T &x) {
    return static_cast<unsigned>(std::upper_bound(v.begin(), v.end(), x) -
                                 v.begin());
}

} // namespace mar