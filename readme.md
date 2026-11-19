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

    1. <op1> -> <op2> <op1'>
    2. <op1'> -> + <op2> <op1'>
    3. <op1'> -> - <op2>  <op1'>
    4. <op1'> -> <alpha>

    5. <op2> -> <op3> <op2'>
    6. <op2'> -> * <op3> <op2'>
    7. <op2'> -> / <op3>  <op2'>
    8. <op2'> -> <alpha>

    9. <op3> -> - <op3>
    10. <op3> -> + <op3>
    11. <op3> -> <op4>


    12. <op4> -> <op5> <op4'>
    13. <op4'> -> ^ <op3>
    14. <op4'> -> <alpha>

    15. <op5> -> NUM
    16. <op5> -> variable
    17. <op5> -> <func> lpar <op1> rpar
    18. <op5> -> lpar <op1> rpar
    19. <func> -> sin
    20. <func> -> cos
    21. <func> -> tan
    22. <func> -> arcsin
    23. <func> -> arccos
    24. <func> -> tan
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

## 6. LL1 verificacion by PREDICT sets 
    PREDICT(<op1'> -> sum <op2> <op1'>)={sum}

    PREDICT(<op1'> -> sub <op2>  <op1'>)={sub}

    PREDICT(<op1'> -> <alpha>)={rpar, $}

    PREDICT(<op2'> -> mult <op3> <op2'>)={mult}

    PREDICT(<op2'> -> div <op3> <op2'>)={div}

    PREDICT(<op2'> -> <alpha>)={sum, sub, rpar, $}

    PREDICT(<op4'> -> exp <op3>)={exp}

    PREDICT(<op4'> -> <alpha>)={mult, div, sum, sub, rpar, $}

    PREDICT(<op3> -> sub <op3>)={sub}

    PREDICT(<op3> -> sum <op3>)={sum}

    PREDICT(<op3> -> <op4>)={NUM, variable, lpar, sin, cos, tan, arcsin, arccos, arctan}

    PREDICT(<op5> -> NUM)={NUM}

    PREDICT(<op5> -> variable)={variable}

    PREDICT(<op5> -> <func> lpar <op1> rpar)={sin, cos, tan, arcsin, arccos, arctan}

    PREDICT(<op5> -> lpar <op1> rpar)={lpar}

    PREDICT(<func> -> sin)={sin}

    PREDICT(<func> -> cos)={cos}

    PREDICT(<func> -> tan)={tan}

    PREDICT(<func> -> arcsin)={arcsin}

    PREDICT(<func> -> arccos)={arccos}

    PREDICT(<func> -> arctan)={arctan}