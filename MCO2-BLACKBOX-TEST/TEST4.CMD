:
:  Test Script for MCO2 (Undirected Graph)
:
:  Usage:  TEST4 
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
IF EXIST D-SET.TXT DEL D-SET.TXT
IF EXIST D-DEGREE.TXT DEL D-DEGREE.TXT
IF EXIST D-LIST.TXT DEL D-LIST.TXT
IF EXIST D-MATRIX.TXT DEL D-MATRIX.TXT
IF EXIST D-BFS.TXT DEL D-BFS.TXT
IF EXIST D-DFS.TXT DEL D-DFS.TXT

ECHO ON
:
: run main.exe 
:
main < T4.TXT

ECHO OFF
ECHO TEST #4 Graph D

: do a bbtest
LBBTEST EXPECTED\EXP-D-SET.TXT    D-SET.TXT      > RESULT-D-SET.TXT 
BBTEST EXPECTED\EXP-D-DEGREE.TXT  D-DEGREE.TXT   > RESULT-D-DEGREE.TXT
BBTEST EXPECTED\EXP-D-LIST.TXT    D-LIST.TXT     > RESULT-D-LIST.TXT
BBTEST EXPECTED\EXP-D-MATRIX.TXT  D-MATRIX.TXT   > RESULT-D-MATRIX.TXT
BBTEST EXPECTED\EXP-D-BFS.TXT     D-BFS.TXT      > RESULT-D-BFS.TXT
BBTEST EXPECTED\EXP-D-DFS.TXT     D-DFS.TXT      > RESULT-D-DFS.TXT

: do a diff test 
ECHO ON
LDIFF EXPECTED\EXP-D-SET.TXT    D-SET.TXT
DIFF EXPECTED\EXP-D-DEGREE.TXT  D-DEGREE.TXT
DIFF EXPECTED\EXP-D-LIST.TXT    D-LIST.TXT
DIFF EXPECTED\EXP-D-MATRIX.TXT  D-MATRIX.TXT
DIFF EXPECTED\EXP-D-BFS.TXT     D-BFS.TXT
DIFF EXPECTED\EXP-D-DFS.TXT     D-DFS.TXT

PROMPT

