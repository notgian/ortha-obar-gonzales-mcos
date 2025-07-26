:
:  Test Script for MCO2 (Undirected Graph)
:
:  Usage:  TEST3 
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
IF EXIST C-SET.TXT DEL C-SET.TXT
IF EXIST C-DEGREE.TXT DEL C-DEGREE.TXT
IF EXIST C-LIST.TXT DEL C-LIST.TXT
IF EXIST C-MATRIX.TXT DEL C-MATRIX.TXT
IF EXIST C-BFS.TXT DEL C-BFS.TXT
IF EXIST C-DFS.TXT DEL C-DFS.TXT

ECHO ON
:
: run main.exe 
:
main < T3.TXT

ECHO OFF
ECHO TEST #3 Graph C

: do a bbtest
LBBTEST EXPECTED\EXP-C-SET.TXT    C-SET.TXT      > RESULT-C-SET.TXT 
BBTEST EXPECTED\EXP-C-DEGREE.TXT  C-DEGREE.TXT   > RESULT-C-DEGREE.TXT
BBTEST EXPECTED\EXP-C-LIST.TXT    C-LIST.TXT     > RESULT-C-LIST.TXT
BBTEST EXPECTED\EXP-C-MATRIX.TXT  C-MATRIX.TXT   > RESULT-C-MATRIX.TXT
BBTEST EXPECTED\EXP-C-BFS.TXT     C-BFS.TXT      > RESULT-C-BFS.TXT
BBTEST EXPECTED\EXP-C-DFS.TXT     C-DFS.TXT      > RESULT-C-DFS.TXT

: do a diff test
ECHO ON
LDIFF EXPECTED\EXP-C-SET.TXT    C-SET.TXT
DIFF EXPECTED\EXP-C-DEGREE.TXT  C-DEGREE.TXT
DIFF EXPECTED\EXP-C-LIST.TXT    C-LIST.TXT
DIFF EXPECTED\EXP-C-MATRIX.TXT  C-MATRIX.TXT
DIFF EXPECTED\EXP-C-BFS.TXT     C-BFS.TXT
DIFF EXPECTED\EXP-C-DFS.TXT     C-DFS.TXT

PROMPT

