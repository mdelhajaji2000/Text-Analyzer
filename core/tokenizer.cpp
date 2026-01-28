#include "tokenizer.hpp"

bool Tokenizer::is_letter(char c) const noexcept
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char Tokenizer::to_lower(char c) const noexcept
{
    if (c >= 'A' && c <= 'Z')
        c += ('a' - 'A');
}

void Tokenizer::flush_current_word(std::string& buffer,
     STL_type::sList<std::string>& out_tokens) const
{
    
    if (!buffer.empty())
    {
        out_tokens.push_front(buffer);
        buffer.clear();
    }
}

void Tokenizer::tokenize(const std::string& text,
     STL_type::sList<std::string>& out_tokens) const
{
    std::string current_word = "";
    for (const auto& c : text)
    {
        if (is_letter(c))
            current_word += to_lower(c);
        else
            flush_current_word(current_word, out_tokens);
        
    }
        flush_current_word(current_word, out_tokens);
}