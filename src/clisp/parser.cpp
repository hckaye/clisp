#include "parser.h"

#include <sstream>

namespace {
enum class lex_char : char {
  lparen = '(',
  rparen = ')',
  space = ' ',
};

lex_char to_lex_char(char c) {
  return static_cast<lex_char>(c);
}
}

namespace clisp {

std::vector<std::string> tokenize(const char *text) {
  std::vector<std::string> tokens;
  std::stringstream current;

  auto const flush_current = [&tokens, &current]() {
    auto const s = current.str();
    if (!s.empty()) {
      tokens.emplace_back(s);
      current.str("");
    }
  };

  for (auto const c : std::string{text}) {
    switch (to_lex_char(c)) {
    case lex_char::lparen:
    case lex_char::rparen:
      flush_current();

      current << c;

      flush_current();
      break;
    case lex_char::space:
      flush_current();
      break;
    default:
      current << c;
      break;
    }
  }

  flush_current();
  return tokens;
}
}
