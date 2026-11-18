## 1. Acepted Symbols
    
    numbers:
        {0,1,2,3,4,5,6,7,8,9}
    key words
        {sin, cos, tan, arcsin, arccos, arctan}
    comma (decimal indicator):
        {','}
    arithmetic operation symbols:
        {+, -, /, *, ^}
    alphabet characters:
        {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z}
    parenthesis:
        {(,)}
## 2. Terminals
    
    digit=[0-9]
    int=digit+
    decimal=,int
    variable=[a-z] | [A-Z]
    NUM=int decimal?
    sum=+
    sub=-
    div=/
    mult=*
    exp=^
    lpar= (
    rpar= )
    sin=sin
    cos=cos
    tan=tan
    arcsin=arcsin
    arccos=arccos
    arctan=arctan

## 3. Precedence
    1. {+,-} // binary
    2. {*,/}
    3. {+,-} // unary
    4. {^}
    5. elemental items such as NUM and trigonometric fucntions are assumed with highest precedence
## 4. Grammar
    <alpha> is empty string

    <op1> -> <op2> <op1'>
    <op1'> -> + <op2> <op1'>
    <op1'> -> - <op2>  <op1'>
    <op1'> -> <alpha>

    <op2> -> <op3> <op2'>
    <op2'> -> * <op3> <op2'>
    <op2'> -> / <op3>  <op2'>
    <op2'> -> <alpha>

    <op3> -> - <op3>
    <op3> -> + <op3>
    <op3> -> <op4>


    <op4> -> <op5> <op4'>
    <op4'> -> ^ <op3>
    <op4'> -> <alpha>

    <op5> -> NUM
    <op5> -> variable
    <op5> -> <func> lpar <op1> rpar
    <op5> -> lpar <op1> rpar
    <func> -> sin
    <func> -> cos
    <func> -> tan
    <func> -> arcsin
    <func> -> arccos
    <func> -> tan
## 5. FIRST and FOLLOW sets
    FIRST(<func>)={sin, cos, tan, arcsin, arccos, arctan}

    FIRST(<op5>)={NUM, variable, lpar, sin, cos, tan, arcsin, arccos, arctan}

    FIRST(<op4'>)={<alpha>, exp}

    FIRST(<op4>)={NUM, variable, lpar, sin, cos, tan, arcsin, arccos, arctan}

    FIRST(<op3>)={sum,sub, NUM, variable, lpar, sin, cos, tan, arcsin, arccos, arctan}

    FIRST(<op2'>)={<alpha>, mult, div}

    FIRST(<op2>)={sum,sub, NUM, variable, lpar, sin, cos, tan, arcsin, arccos, arctan}

    FIRST(<op1'>)={<alpha>, sum, sub}

    FIRST(<op1>)={sum,sub, NUM, variable, lpar, sin, cos, tan, arcsin, arccos, arctan}


    FOLLOW(<op1>)={rpar, $}

    FOLLOW(<op1'>)={rpar, $}
    
    FOLLOW(<op2>)={sum, sub, rpar, $}

    FOLLOW(<op2'>)={sum, sub, rpar, $}

    FOLLOW(<op3>)={mult, div, sum, sub, rpar, $}

    FOLLOW(<op4>)={mult, div, sum, sub, rpar, $}

    FOLLOW(<op4'>)={mult, div, sum, sub, rpar, $}

    FOLLOW(<op5>)={exp, mult, div, sum, sub, rpar, $}

    FOLLOW(<func>)={lpar}
