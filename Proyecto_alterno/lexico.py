from ply311.ply import lex as lex
import re
import codecs
import os
import sys

# definir tokens

reservadas = {
    "auto" : "AUTO", 
    "double" : "DOUBLE", 
    "int" : "INT", 
    "struct" : "STRUCT", 
    "break" : "BREAK", 
    "else" : "ELSE", 
    "long" : "LONG", 
    "switch" : "SWITCH", 
    "case" : "CASE", 
    "enum" : "ENUM", 
    "register" : "REGISTER", 
    "typedef" : "TYPEDEF", 
    "char" : "CHAR", 
    "extern" : "EXTERN", 
    "return" : "RETURN", 
    "union" : "UNION", 
    "const" : "CONST", 
    "float" : "FLOAT", 
    "short" : "SHORT", 
    "unsigned" : "UNSIGNED", 
    "continue" : "CONTINUE", 
    "for" : "FOR", 
    "signed" : "SIGNED", 
    "void" : "VOID", 
    "default" : "DEFAULT", 
    "goto" : "GOTO", 
    "sizeof" : "SIZEOF", 
    "volatile" : "VOLATILE", 
    "do" : "DO", 
    "if" : "IF", 
    "static" : "STATIC", 
    "while" : "WHILE"}

tokens = list(reservadas.values()) + ["ID","NUMBER","PLUS","MINUS","MULT","DIVIDE","ASSIGN","MR","LF","MOD","PLUSEQL",
        "LESSEQL","MULTEQL","DIVIDEEQL","MREQL","LFEQL","EQLEQL","DIFEQL","ANDAND","OROR","PLUSPLUS","LESSLESS"]

t_PLUS = r'\+'
t_ASSIGN = r'='
t_MULT = r'\*'
t_DIVIDE = r'\/'
t_MR = r'>'
t_LF = r'<'
t_MOD = r'%'
t_PLUSEQL = r'\+='
t_LESSEQL = r'-='
t_MULTEQL = r'\*='
t_DVIDEEQL = r'/='
t_MREQL = r'>='
t_LFEQL = r'<='
t_DIFEQL = r'!='
t_ANDAND = r'&&'
t_OROR = r'\|\|'
t_PLUSPLUS = r'\+\+'
t_LESSLESS = r'\-\-'

def t_ID(t):
    r'[a-zA-Z_][a-zA-Z0-9_]*'

    if t.value.upper() in keywords:
        t.value = t.value.upper()
        t.type = t.value

    return t


def t_COMMENT(c):
    