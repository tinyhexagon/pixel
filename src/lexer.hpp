#pragma once
#include "global.hpp"

namespace lexer
{
    vector<token> tokens = {};
    string buffer;
    char current_char;
    char next_char;
    bool in_quotes = false;
    int quotes = 0;

    inline void push_token(token_type type, string value)
    {
        tokens.push_back({.type = type, .value = value});
        buffer.clear();
    }

    void push_keyword(string keyword, token_type type)
    {
        if (buffer == keyword)
        {
            push_token(type, "");
        }
    }

    void push_symbol(string symbol, token_type type)
    {
        if (buffer == symbol)
        {
            push_token(type, "");
        }
    }

    void push_operator(char _operator, token_type type)
    {
        if ((buffer.front() == _operator && buffer.back() == _operator) && _operator != next_char && buffer.length() == 1)
        {
            push_token(type, "");
        }
    }

    void push_two_char_operator(char firstChar, char lastChar, token_type type)
    {
        if ((buffer.front() == firstChar && buffer.back() == lastChar) && buffer.length() == 2)
        {
            push_token(type, "");
        }
    }

    int get_number()
    {

        if (buffer.empty())
        {
            return RUN_FAIL;
        }

        for (char c : buffer)
        {
            if (!isdigit(c) && c != '.')
            {
                return RUN_FAIL;
            }
        }

        if (!isdigit(next_char) && next_char != '.')
        {
            push_token(numeric_literal, buffer);
            return RUN_SUCCESS;
        }

        return RUN_SUCCESS;
    }

    void lex_file(ifstream &source_file)
    {
        while (source_file.get(current_char))
        {
            next_char = source_file.peek();

            if (!std::isspace(current_char) || in_quotes)
            {
                buffer.push_back(current_char);
            }

            if (current_char == '"' && buffer.front() == '"' || current_char == '\'' && buffer.front() == '\'')
            {
                quotes++;
                in_quotes = true;
            }

            if (quotes == 2)
            {
                in_quotes = false;
                push_token(token_type::string_literal, buffer);
                quotes = 0;
            }

            push_operator('+', token_type::plus);
            push_operator('-', token_type::dash);
            push_operator('*', token_type::asterik);
            push_operator('/', token_type::slash);
            push_operator('%', token_type::percent);
            push_operator('=', token_type::assign);
            push_operator('!', token_type::exclaimation);

            push_keyword("print", token_type::_print);
            push_keyword("int", token_type::_int);
            push_keyword("dec", token_type::_dec);
            push_keyword("string", token_type::_string);
            push_keyword("bool", token_type::_bool);
            push_keyword("mut", token_type::_const);
            push_keyword("null", token_type::_null);
            push_keyword("fn", token_type::_fn);
            push_keyword("if", token_type::_if);
            push_keyword("for", token_type::_for);
            push_keyword("while", token_type::_while);
            push_keyword("true", token_type::_true);
            push_keyword("false", token_type::_false);
            push_keyword("return", token_type::_return);

            push_symbol(";", token_type::semicolon);
            push_symbol("(", token_type::o_paren);
            push_symbol(")", token_type::c_paren);
            push_symbol("{", token_type::o_curly);
            push_symbol("}", token_type::c_curly);
            push_symbol("[", token_type::o_brack);
            push_symbol("]", token_type::c_brack);
            push_symbol("?", token_type::question);

            if ((isalpha(buffer.front()) || buffer.front() == '_') && (!isalnum(next_char) && next_char != '_') && !in_quotes)
            {
                push_token(token_type::identifier, buffer);
            }

            if (isdigit(buffer.front()) && !isdigit(next_char) && next_char != '.')
            {
                push_token(token_type::numeric_literal, buffer);
            }
        }

        push_token(token_type::eof, "");
    }

};

/*

// operators

pushTwoCharOperator('=', '=', token_type::equals);
pushTwoCharOperator('*', '*', token_type::exponentiation);
pushTwoCharOperator('+', '+', token_type::increment);

*/