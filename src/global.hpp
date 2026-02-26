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

    /*0*/ numeric_literal,
    /*1*/ string_literal,

    // operators

    /*2*/ plus,
    /*3*/ dash,
    /*4*/ asterik,
    /*5*/ slash,
    /*6*/ percent,
    /*7*/ assign,
    /*8*/ exclaimation,

    /*9*/ identifier,

    // keywords

    /*10*/ _print,
    /*11*/ _int,
    /*12*/ _dec,
    /*13*/ _string,
    /*14*/ _bool,
    /*15*/ _const,
    /*16*/ _null,
    /*17*/ _if,
    /*18*/ _for,
    /*19*/ _while,
    /*20*/ _fn,
    /*21*/ _true,
    /*22*/ _false,
    /*23*/ _return,

    // symbols

    /*24*/ semicolon,
    /*25*/ colon,
    /*26*/ o_paren,
    /*27*/ c_paren,
    /*28*/ o_curly,
    /*29*/ c_curly,
    /*30*/ o_brack,
    /*31*/ c_brack,
    /*32*/ dot,
    /*33*/ comma,
    /*34*/ question,

    /*E*/ eof,
};

struct token
{
    token_type type;
    string value;
};