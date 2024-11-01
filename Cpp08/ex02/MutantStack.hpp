#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
  typename std::stack<T>::container_type& getContainer() {
        return this->c; // 'c' std::stack'te protected üye olarak, asıl konteyneri temsil eder
    }
};


#endif
