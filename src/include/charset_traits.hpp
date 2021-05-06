#pragma once
#include <iostream>
#include <string>

namespace mmo
{

struct charset_traits : std::char_traits<char>
{
    using traits_type = std::char_traits<char>;
    using char_type = char;
    using int_type = typename traits_type::int_type;
    using istream_type = std::istream;
    using string_type = std::string;


    enum take_options
    {
        NONE,
        IGNORE,
        CONSUME
    };

    static constexpr int_type
    eol()
    {
        return traits_type::to_int_type('\n');
    }

    inline static constexpr bool
    is_padding(
        char_type ch)
    {
        return (ch <= 32);
    }

    inline static constexpr bool
    is_padding(
        int_type n)
    {
        return (n <= 32);
    }

    inline static constexpr bool
    is_eol(
        char_type                       ch
    ) {
        return ( traits_type::to_int_type(ch) == eol());
    }

    inline static constexpr bool
    is_eol(
        int_type                        n
    ) {
        constexpr auto a = traits_type::to_int_type('\n');
        return (n == a);
    }



    static const char_type *
    find(
        char_type ch,
        const char_type *p)
    {
        while (*p && *p != ch)
            ++p;
        return (*p == 0) ? nullptr : p;
    }

    inline static const char_type *
    find(
        const char_type *p,
        std::size_t count,
        const char_type &ch)
    {
        return traits_type::find(p, count, ch);
    }


    static void
    ignore_padding(
        istream_type &ist)
    {
        auto nx = ist.peek();
        while (!ist.eof() && is_padding(nx))
        {
            ist.get();
            nx = ist.peek();
        }
    }

    static void
    remove_padding_right(
        string_type &str)
    {
        while (!str.empty() && is_padding(str.back()))
            str.pop_back();
    }

    static void
    remove_padding_left(
        string_type &str)
    {
        if(!str.empty() && is_padding(str.front())) {
            std::size_t i = 1;
            for(; (i < str.size() && is_padding(str[i])); ++i) ;
            str = std::move(str.substr(i));
        }
    }

    static void
    remove_padding(
        string_type &str)
    {
        remove_padding_left(str);
        remove_padding_right(str);
    }

    static void
    ignore_until(
        istream_type &ist,
        char_type ch,
        take_options consume = NONE)
    {
        char nx = traits_type::to_char_type(ist.peek());
        while (!ist.eof() && (ch != nx))
        {
            ist.get();
            nx = traits_type::to_char_type(ist.peek());
        }
        if (consume > NONE && !ist.eof())
        {
            ist.get();
        }
    }

    static void
    ignore_until(
        std::istream &ist,
        const char_type *arr,
        take_options consume = NONE)
    {
        char nx = traits_type::to_char_type(ist.peek());
        while (!ist.eof() && (find(nx, arr) == nullptr))
        {
            ist.get();
            nx = traits_type::to_char_type(ist.peek());
        }
        if (consume > NONE && !ist.eof())
        {
            ist.get();
        }
    }


    static string_type
    take_until(
        istream_type &ist,
        char_type ch,
        take_options consume = NONE)
    {
        string_type ret;
        char nx = traits_type::to_char_type(ist.peek());
        while (!ist.eof() && (ch != nx))
        {
            ret.push_back(nx);
            ist.get();
            nx = traits_type::to_char_type(ist.peek());
        }
        if (consume > NONE && !ist.eof())
        {
            ist.get();
            if (consume == CONSUME)
                ret.push_back(nx);
        }
        return ret;
    }

    static string_type
    take_until(
        std::istream &ist,
        const char_type *arr,
        take_options consume = NONE)
    {
        string_type ret;
        char nx = traits_type::to_char_type(ist.peek());
        while (!ist.eof() && (find(nx, arr) == nullptr))
        {
            ret.push_back(nx);
            ist.get();
            nx = traits_type::to_char_type(ist.peek());
        }
        if (consume > NONE && !ist.eof())
        {
            ist.get();
            if (consume == CONSUME)
                ret.push_back(nx);
        }
        return ret;
    }

}; // struct charset_traits

} // namespace mmo