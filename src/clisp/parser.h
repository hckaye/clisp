#ifndef CLISP_PARSER_H
#define CLISP_PARSER_H

#include <string>
#include <vector>

#include "exp.h"

namespace clisp {
// text must be ascii string
std::vector<std::string> tokenize(const char* text);
std::vector<exp> parse_tokens(const std::vector<std::string>& tokens);
}

#endif //CLISP_PARSER_H
