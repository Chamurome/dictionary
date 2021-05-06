#pragma once
#include "charset_traits.hpp"
#include <map>

namespace mmo
{

struct dictionary_traits
{
    using traits_type = charset_traits;
    using char_type = typename traits_type::char_type;
    using int_type = typename traits_type::int_type;
    using istream_type = typename traits_type::istream_type;
    using string_type = typename traits_type::string_type;
    using take_options = typename traits_type::take_options;

    inline static constexpr bool
    is_quote(
        char_type ch
    ) {
        return ( ch=='\'' ) || ( ch=='"' );
    }

    inline static constexpr bool
    is_quote(
        int_type n
    ) {
        constexpr auto a= traits_type::to_int_type('\'');
        constexpr auto b= traits_type::to_int_type('"');
        return ( n==a ) || ( n==b );
    }

    /**
     * @brief
     *
     * @param ist
     * @return string_type
     */
    static string_type
    take_literal(
        istream_type                        &ist
    ) {
        string_type ret;
        auto ch = ist.peek();
        if( !ist.eof() && is_quote(ch) ) {
            ist.get();
            ret = traits_type::take_until(ist, ch, traits_type::IGNORE);
        }
        return ret;
    }

    static string_type
    take_data(
        istream_type                        &ist,
        char_type                           separator,
        take_options                        consume= take_options::NONE
    ) {
        traits_type::ignore_padding(ist);
        string_type ret = take_literal(ist);
        if(ret.empty()) {
            ret = traits_type::take_until(ist, separator, consume);
        } else {
            traits_type::ignore_until(ist, separator, consume);
        }
        return ret;
    }

}; // struct dictionary_traits

} // namespace mmo