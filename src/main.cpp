#include "dictionary_traits.hpp"
#include <iostream>
#include <sstream>

using namespace mmo;

int main()
{
    std::istringstream ist("'    pardiez'   : '     manolo    '    ");

    charset_traits::ignore_padding(ist);
    auto str = dictionary_traits::take_data(ist, ':', dictionary_traits::take_options::CONSUME);
    std::cout << '>' << str << '<' << '\n';
    str = dictionary_traits::take_data(ist, ',');
    std::cout << '>' << str << '<' << '\n';
    charset_traits::remove_padding(str);
    std::cout << '>' << str << '<' << '\n';

    return 0;
}