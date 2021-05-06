#pragma once
#include "charset_traits.hpp"
#include <iostream>
#include <string>
#include <map>

namespace mmo
{
    namespace __mmo
    {

        void
        take_key(
            std::istream &ist,
            std::string &str)
        {
            using traits_type = charset_traits;
            using char_type = typename charset_traits::char_type;

            char nx;
            char_tratis::ignore_padding(ist);
            ist.get(nx);
            if ((nx == '\'') || (nx == '"'))
            {
                __mmo::take_until(ist, nx, str);
                ist.get();
                __mmo::ignore_padding(ist);
                if (ist.eof())
                    throw "Waiting for value";
                ist.get(nx);
                if (nx != ':')
                    throw "Waiting for ':'";
            }
            else
            {
                str.push_back(nx);
                __mmo::take_until(ist, ':', str);
                if (ist.eof())
                    throw "Waiting for value";
                ist.get();
            }
        }

    } // namespace __mmo

    void load(
        std::istream &ist)
    {
        using traits = std::char_traits<char>;
        while (!ist.eof())
        {
            std::string str;
            __mmo::take_key(ist, str);
            std::cout << str << '\n';
            break;
        }
    }

} // namespace mmo