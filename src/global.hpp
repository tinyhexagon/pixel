#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#define RUN_SUCCESS 0
#define RUN_FAIL 1

using std::cout, std::ifstream, std::vector, std::string;

namespace fs = std::filesystem;

enum class token_type
{
    // literals
    numeric_literal,
    string_literal,

    // operators
    plus,
    dash,
    asterik,
    slash,
    percent,
    assign,

    unary,

    greater,
    less,

    logical_not,
    logical_and,
    logical_or,

    increment,
    decrement,
    greater_eq,
    less_eq,

    identifier,

    // keywords
    _print,
    _int,
    _dec,
    _string,
    _bool,
    _const,
    _null,
    _if,
    _for,
    _while,
    _fn,
    _true,
    _false,
    _return,

    // symbols
    semicolon,
    colon,
    o_paren,
    c_paren,
    o_curly,
    c_curly,
    o_brack,
    c_brack,
    dot,
    comma,
    question,

    eof,
};

struct token
{
    token_type type;
    string value;
};