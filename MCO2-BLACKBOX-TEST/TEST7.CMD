:
:  Test Script for MCO2 (Undirected Graph)
:
:  Usage:  TEST7 
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
main < T7.TXT
ECHO OFF
ECHO TEST #7 Graph G

: 
: Test case for a not found start vertex for BFS and DFS traversal.
: Should still produce Output Text Files #1 to #4 but not #5 and #6.
: Should report a "Vertex CLARK not found." error message.
:
ECHO ** Check if Output Files #1 to #4 were produced **
ECHO ON
DIR G-*.TXT

PROMPT

