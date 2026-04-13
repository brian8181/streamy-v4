/**
 * @file    parser.hpp
 * @version 0.0.1
 * @date    Sat, 04 Apr 2026 12:59:28 +0000
 * @info    ...
 */
#include "parser.hpp"
// #include "tokens.hpp"
//  using namespace bkp;

bkp::parser::parser(context *ct, const string &file) : m_context(ct), m_file(file)
{
    read_str(m_file, m_input, std::ios::in);
}

token_value_t *parse()
{
    while (true)
    {
        // get token
        auto token = lexer::instance().get_token();
        if (token.kind() == END_OF_FILES)
        {
            cout << FMT_FG_DARK_GREY << "*******************************************************" << FMT_RESET << endl;
            cout << FMT_FG_DARK_GREY << "*                      End Of Files                   *" << FMT_RESET << endl;
            cout << FMT_FG_DARK_GREY << "*******************************************************" << FMT_RESET << endl;
            break; // end of files
        }
        else if (token.kind() == END_OF_FILE)
        {
            cout << FMT_FG_DARK_GREY << "*******************************************************" << FMT_RESET << endl;
            cout << FMT_FG_DARK_GREY << "*                      End Of File                    *" << FMT_RESET << endl;
            cout << FMT_FG_DARK_GREY << "*******************************************************" << FMT_RESET << endl;
            break; // end of file
        }
        else
        {
            cout << FMT_FG_DARK_GREY << "*******************************************************" << FMT_RESET << endl;
            cout << FMT_FG_DARK_GREY << "*                      Token: " << token.kind() << "                   *" << FMT_RESET << endl;
            cout << FMT_FG_DARK_GREY << "*******************************************************" << FMT_RESET << endl;
            // process token ...
        }
    }
}
