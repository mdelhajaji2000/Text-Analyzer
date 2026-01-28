#pragma once

#include <string>
#include "../containers/sList.h"

class Tokenizer
{
public:
    void tokenize(const std::string& text,
                  STL_type::sList<std::string>& out_tokens) const;

private:
    bool is_letter(char c) const noexcept;

    char to_lower(char c) const noexcept;

    void flush_current_word(std::string& buffer,
                            STL_type::sList<std::string>& out_tokens) const;
};
