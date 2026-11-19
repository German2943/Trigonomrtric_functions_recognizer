#ifndef TOKENIZER_H
#define TOKENIZER_H
enum terminal
{
    NUM,
    VAR,
    SUM,
    SUB,
    MULT,
    DIV,
    EPX,
    LPAR,
    RPAR,
    SIN,
    COS,
    TAN,
    ARCSIN,
    ARCCOS,
    ARCTAN,
    INPUT_END
};

typedef struct token
{
    char *lexem;
    terminal TERMINAL;
} token;

#endif TOKENIZER_H
