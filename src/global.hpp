#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#define RUN_SUCCESS 0
#define RUN_FAIL 1

using std::cout, std::ifstream, std::vector, std::string;

namespace fs = std::filesystem;


enum token_type
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

    /*E*/ eof,
};

struct token
{
    token_type type;
    string value;
};