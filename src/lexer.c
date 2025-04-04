#include "include/lexer.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

lexer_T *init_lexer(char *contents) {
  lexer_T *lexer = calloc(1, sizeof(lexer_T));
  lexer->contents = contents;
  lexer->i = 0;
  lexer->c = contents[lexer->i];

  return lexer;
}

void lexer_advance(lexer_T *lexer) {
  if (lexer->c != '\0' && lexer->i < strlen(lexer->contents)) {
    ++lexer->i;
    lexer->c = lexer->contents[lexer->i];
  }

  return;
}

void lexer_skip_whitespace(lexer_T *lexer) {
  if (lexer->c == ' ' || lexer->c == '\n') {
    lexer_advance(lexer);
  }
}

token_T *lexer_get_next_token(lexer_T *lexer) {
  while (lexer->c != '\0' && lexer->i < strlen(lexer->contents)) {
    if (lexer->c == ' ' || lexer->c == 10) {
      lexer_skip_whitespace(lexer);
    }

    if (isalnum(lexer->c)) {
      return lexer_collect_id(lexer);
    }

    if (lexer->c == '"') {
      return lexer_collect_string(lexer);
    }

    switch (lexer->c) {
    case '=':
      return lexer_advance_with_token(
          lexer, init_token(TOKEN_EQUALS, lexer_get_char_string(lexer)));
      break;
    case ';':
      return lexer_advance_with_token(
          lexer, init_token(TOKEN_SEMI, lexer_get_char_string(lexer)));
      break;
    case '(':
      return lexer_advance_with_token(
          lexer, init_token(TOKEN_LPAREN, lexer_get_char_string(lexer)));
      break;
    case ')':
      return lexer_advance_with_token(
          lexer, init_token(TOKEN_RPAREN, lexer_get_char_string(lexer)));
      break;
    }
  }

  return (void *)0;
}

token_T *lexer_collect_string(lexer_T *lexer) {
  lexer_advance(lexer);
  char *val = calloc(1, sizeof(char));
  val[0] = '\0';

  while (lexer->c != '"') {
    char *s = lexer_get_char_string(lexer);
    val = realloc(val, (strlen(val) + strlen(s) + 1) * sizeof(char));
    strcat(val, s);

    lexer_advance(lexer);
  }

  lexer_advance(lexer);

  return init_token(TOKEN_STRING, val);
}

token_T *lexer_collect_id(lexer_T *lexer) {
  char *val = calloc(1, sizeof(char));
  val[0] = '\0';

  while (isalnum(lexer->c)) {
    char *s = lexer_get_char_string(lexer);
    val = realloc(val, (strlen(val) + strlen(s) + 1) * sizeof(char));
    strcat(val, s);

    lexer_advance(lexer);
  }

  lexer_advance(lexer);
  return init_token(TOKEN_ID, val);
}

token_T *lexer_advance_with_token(lexer_T *lexer, token_T *token) {
  lexer_advance(lexer);

  return token;
}

char *lexer_get_char_string(lexer_T *lexer) {
  char *str = calloc(2, sizeof(char));
  str[0] = lexer->c;
  str[1] = '\0';
  return str;
}
