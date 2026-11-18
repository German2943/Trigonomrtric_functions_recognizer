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
    6. elemental items such as NUM and trigonometric fucntions are assumed with highest precedence