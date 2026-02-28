#include "global.hpp"
#include "lexer.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "\033[31mNo arguments provided.\033[0m\n";
        return RUN_FAIL;
    }

    vector<string> args = {};
    args.reserve(argc);

    for (int i = 0; i < argc; i++)
    {
        args.push_back(argv[i]);
    }

    for (string str : args)
    {
        if (str == "--version")
        {
            cout << "Pixel 0.1 by unityLeaf7\n";
            return RUN_SUCCESS;
        }

        if (str == "--help")
        {
            cout << "\nFlag \t\tUse\n----------------------------------\n";
            cout << "--help  \tShows this page\n";
            cout << "--version  \tShows Pixel language version\n";
            cout << "--wiki  \tProvides GitHub wiki for Pixel\n";
            return RUN_SUCCESS;
        }
    }

    fs::path source_path = argv[1];

    if (!fs::exists(source_path))
    {
        cout << "\033[31mFile does not exist.\033[0m\n";
        return RUN_FAIL;
    }

    if (source_path.extension().string() != ".pixel")
    {
        cout << "\033[31mWrong file extension.\033[0m\n";
        return RUN_FAIL;
    }

    ifstream source_file(source_path, std::ios::in);

    lexer::lex_file(source_file);
    lexer::process_tokens();

    cout << "\nToken Type\tValue\n";
    cout << "-----------------------\n";

    for (const token &tk : lexer::tokens)
    {
        switch (tk.type)
        {
        case token_type::numeric_literal:
            cout << "number  \t";
            break;
        case token_type::string_literal:
            cout << "string  \t";
            break;
        case token_type::plus:
            cout << "operator \t+";
            break;
        case token_type::dash:
            cout << "operator \t-";
            break;
        case token_type::asterik:
            cout << "operator \t*";
            break;
        case token_type::slash:
            cout << "operator \t/";
            break;
        case token_type::percent:
            cout << "operator \t%";
            break;
        case token_type::assign:
            cout << "operator \t=";
            break;
        case token_type::logical_not:
            cout << "operator \t!";
            break;
        case token_type::identifier:
            cout << "identifier \t";
            break;
        case token_type::_print:
            cout << "keyword \tprint";
            break;
        case token_type::_int:
            cout << "keyword \tint";
            break;
        case token_type::_dec:
            cout << "keyword \tdec";
            break;
        case token_type::_string:
            cout << "keyword \tstring";
            break;
        case token_type::_bool:
            cout << "keyword \tbool";
            break;
        case token_type::_const:
            cout << "keyword \tconst";
            break;
        case token_type::_null:
            cout << "keyword \tnull";
            break;
        case token_type::_if:
            cout << "keyword \tif";
            break;
        case token_type::_for:
            cout << "keyword \tfor";
            break;
        case token_type::_while:
            cout << "keyword \twhile";
            break;
        case token_type::_fn:
            cout << "keyword \tfn";
            break;
        case token_type::_true:
            cout << "keyword \ttrue";
            break;
        case token_type::_false:
            cout << "keyword \tfalse";
            break;
        case token_type::_return:
            cout << "keyword \treturn";
            break;
        case token_type::semicolon:
            cout << "symbol  \t;";
            break;
        case token_type::colon:
            cout << "symbol  \t:";
            break;
        case token_type::o_paren:
            cout << "symbol  \t(";
            break;
        case token_type::c_paren:
            cout << "symbol  \t)";
            break;
        case token_type::o_curly:
            cout << "symbol  \t{";
            break;
        case token_type::c_curly:
            cout << "symbol  \t}";
            break;
        case token_type::o_brack:
            cout << "symbol  \t[";
            break;
        case token_type::c_brack:
            cout << "symbol  \t]";
            break;
        case token_type::dot:
            cout << "symbol  \t.";
            break;
        case token_type::comma:
            cout << "symbol  \t,";
            break;
        case token_type::question:
            cout << "symbol  \t?";
            break;
        case token_type::increment:
            cout << "operator  \t++";
            break;
        case token_type::decrement:
            cout << "operator  \t--";
            break;
        case token_type::greater:
            cout << "operator  \t>";
            break;
        case token_type::less:
            cout << "operator  \t<";
            break;
        case token_type::greater_eq:
            cout << "operator  \t<=";
            break;
        case token_type::less_eq:
            cout << "operator  \t>=";
            break;
        case token_type::unary:
            cout << "unary \t\t(negative)";
            break;

        case token_type::eof:
            cout << "<EOF>\t";
            break;

        default:
            cout << "<unknown token type: " << static_cast<int>(tk.type) << ">\t";
            break;
        }

        cout << tk.value << "\n";
        cout << "-----------------------\n";
    }

    source_file.close();
    return RUN_SUCCESS;
}