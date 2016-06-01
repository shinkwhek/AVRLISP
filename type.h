/*
 * File: type.h
 *
 * There're tiny structure to implement S-Expression.
 * This file is included all of .c files as BASIC STRUCTURE.
 *
 */

#ifndef _TYPE_H
#define _TYPE_H

#include <stdio.h>
#include <string.h>

//--- Types ---//
#define NIL         (0)
#define NUMBER      (1)
#define OPERATION   (2)
#define CONS        (3)
//-------------//
#define MAX_LIST (100)

typedef struct SExpression {
    /* Type of S-Expression.
     *  | NIL
     *  | NUMBER
     *  | OPERATION
     *  | CONS
     */
    int _type;

    /* Atom or Expression.
     *  | Number      -> Atom
     *  | OPERATION   -> Atom
     *  | Cons        -> Car Expression
     */
    char * _data;

    /* Only Expression.
     * | Cdr Expression
     * | NIL (NULL)
     *
     * Example:
     *  (+ 1 (+ 2 3))
     *   | OPERATION:[0]:"+"
     *   | NUMBER:   [1]:"1"
     *   | CONS:     [2]:redix
     *        | OPERATION:[2]->_next[0]:"+"
     *        | NUMBER:   [2]->_next[1]:"2"
     *        | NUMBER   :[2]->_next[2]:"3"
     */

    struct SExpression ** _next;

} SExpr;

void
print_expr (SExpr * expr)
{
    if (expr->_type == NUMBER) {
        printf("%s", expr->_data);
    }
    if (expr->_type == OPERATION) {
        printf("%s", expr->_data);
    }

    if (expr->_type != NIL){
        int i = 1;
        for (i; i < MAX_LIST; i++){
            switch (expr[i]._type){
                case NIL:
                    break;
                case NUMBER:
                    printf("%s", expr[i]._type);
                    break;
                case OPERATION:
                    printf("%s", expr[i]._type);
                    break;
                case CONS:
                    printf("(");
                    print_expr(&expr[i]);
                    break;
                default:
                    printf(")");
            }
        }
    }
}

#endif // _TYPE_H
