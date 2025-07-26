:
:  Test Script for MCO2 (Undirected Graph)
:
:  Usage:  TEST2
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
IF EXIST B-SET.TXT DEL B-SET.TXT
IF EXIST B-DEGREE.TXT DEL B-DEGREE.TXT
IF EXIST B-LIST.TXT DEL B-LIST.TXT
IF EXIST B-MATRIX.TXT DEL B-MATRIX.TXT
IF EXIST B-BFS.TXT DEL B-BFS.TXT
IF EXIST B-DFS.TXT DEL B-DFS.TXT

ECHO ON
:
: run main.exe 
:
main < T2.TXT

ECHO OFF
ECHO TEST #2 Graph B

: do a bbtest
LBBTEST EXPECTED\EXP-B-SET.TXT    B-SET.TXT      > RESULT-B-SET.TXT 
BBTEST EXPECTED\EXP-B-DEGREE.TXT  B-DEGREE.TXT   > RESULT-B-DEGREE.TXT
BBTEST EXPECTED\EXP-B-LIST.TXT    B-LIST.TXT     > RESULT-B-LIST.TXT
BBTEST EXPECTED\EXP-B-MATRIX.TXT  B-MATRIX.TXT   > RESULT-B-MATRIX.TXT
BBTEST EXPECTED\EXP-B-BFS.TXT     B-BFS.TXT      > RESULT-B-BFS.TXT
BBTEST EXPECTED\EXP-B-DFS.TXT     B-DFS.TXT      > RESULT-B-DFS.TXT

: do a diff test 
ECHO ON
LDIFF EXPECTED\EXP-B-SET.TXT    B-SET.TXT
DIFF EXPECTED\EXP-B-DEGREE.TXT  B-DEGREE.TXT
DIFF EXPECTED\EXP-B-LIST.TXT    B-LIST.TXT
DIFF EXPECTED\EXP-B-MATRIX.TXT  B-MATRIX.TXT
DIFF EXPECTED\EXP-B-BFS.TXT     B-BFS.TXT
DIFF EXPECTED\EXP-B-DFS.TXT     B-DFS.TXT

PROMPT

