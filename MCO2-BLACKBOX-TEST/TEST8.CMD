:
:  Test Script for MCO2 (Undirected Graph)
:
:  Usage:  TEST8
:
ECHO OFF
PROMPT $g
gcc -Wall bbtest.c -o bbtest.exe
gcc -Wall Lbbtest.c -o Lbbtest.exe
gcc -Wall diff.c -o diff.exe
gcc -Wall Ldiff.c -o Ldiff.exe

:
: For the MCO2 demo, assume that:
: 1. student has compiled main.c without any syntax error
: 2. the exe file was named as main.exe
:
: delete possible garbage data (to avoid possible problems on a repeat run)
IF EXIST G-SET.TXT DEL G-SET.TXT
IF EXIST G-DEGREE.TXT DEL G-DEGREE.TXT
IF EXIST G-LIST.TXT DEL G-LIST.TXT
IF EXIST G-MATRIX.TXT DEL G-MATRIX.TXT
IF EXIST G-BFS.TXT DEL G-BFS.TXT
IF EXIST G-DFS.TXT DEL G-DFS.TXT
ECHO ON
:
: run main.exe 
:
main < T8.TXT
ECHO OFF
ECHO TEST #8 Graph Q (Q.TXT does not exist)

: 
: Test case for an input text file that does not exist.
: Should NOT Output Text Files #1 to #6.
: Should report a "File Q.TXT file not found." error message AND then terminate.
:
ECHO ** Check if Output Files #1 to #6 were produced **
ECHO ON
DIR Q-*.TXT

PROMPT

