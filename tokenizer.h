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
    ARCTAN
};

typedef struct token
{
    char *lexem;
    enum terminal Termnial;
} token;

#endif TOKENIZER_H
