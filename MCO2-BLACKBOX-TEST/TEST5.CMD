:
:  Test Script for MCO2 (Undirected Graph)
:
:  Usage:  TEST5 
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
IF EXIST E-SET.TXT DEL E-SET.TXT
IF EXIST E-DEGREE.TXT DEL E-DEGREE.TXT
IF EXIST E-LIST.TXT DEL E-LIST.TXT
IF EXIST E-MATRIX.TXT DEL E-MATRIX.TXT
IF EXIST E-BFS.TXT DEL E-BFS.TXT
IF EXIST E-DFS.TXT DEL E-DFS.TXT

ECHO ON
:
: run main.exe 
:
main < T5.TXT

ECHO OFF
ECHO TEST #5 Graph E

: do a bbtest
LBBTEST EXPECTED\EXP-E-SET.TXT    E-SET.TXT      > RESULT-E-SET.TXT 
BBTEST EXPECTED\EXP-E-DEGREE.TXT  E-DEGREE.TXT   > RESULT-E-DEGREE.TXT
BBTEST EXPECTED\EXP-E-LIST.TXT    E-LIST.TXT     > RESULT-E-LIST.TXT
BBTEST EXPECTED\EXP-E-MATRIX.TXT  E-MATRIX.TXT   > RESULT-E-MATRIX.TXT
BBTEST EXPECTED\EXP-E-BFS.TXT     E-BFS.TXT      > RESULT-E-BFS.TXT
BBTEST EXPECTED\EXP-E-DFS.TXT     E-DFS.TXT      > RESULT-E-DFS.TXT

: do a diff test 
ECHO ON
LDIFF EXPECTED\EXP-E-SET.TXT    E-SET.TXT
DIFF EXPECTED\EXP-E-DEGREE.TXT  E-DEGREE.TXT
DIFF EXPECTED\EXP-E-LIST.TXT    E-LIST.TXT
DIFF EXPECTED\EXP-E-MATRIX.TXT  E-MATRIX.TXT
DIFF EXPECTED\EXP-E-BFS.TXT     E-BFS.TXT
DIFF EXPECTED\EXP-E-DFS.TXT     E-DFS.TXT

PROMPT

