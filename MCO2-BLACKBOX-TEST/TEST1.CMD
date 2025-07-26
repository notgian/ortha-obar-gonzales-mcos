:
:  Test Script for MCO2 (Undirected Graph)
:
:  Usage:  TEST1 
:
ECHO OFF
PROMPT $g
C:\MinGW\bin\gcc -Wall bbtest.c -o bbtest.exe
C:\MinGW\bin\gcc -Wall Lbbtest.c -o Lbbtest.exe
C:\MinGW\bin\gcc -Wall diff.c -o diff.exe
C:\MinGW\bin\gcc -Wall Ldiff.c -o Ldiff.exe

:
: For the MCO2 demo, assume that:
: 1. student has compiled main.c without any syntax error
: 2. the exe file was named as main.exe
:
: delete possible garbage data (to avoid possible problems on a repeat run)
IF EXIST A-SET.TXT DEL A-SET.TXT
IF EXIST A-DEGREE.TXT DEL A-DEGREE.TXT
IF EXIST A-LIST.TXT DEL A-LIST.TXT
IF EXIST A-MATRIX.TXT DEL A-MATRIX.TXT
IF EXIST A-BFS.TXT DEL A-BFS.TXT
IF EXIST A-DFS.TXT DEL A-DFS.TXT

ECHO ON
:
: run main.exe 
:
main < T1.TXT

ECHO OFF
ECHO TEST #1 Graph A

: do a bbtest
LBBTEST EXPECTED\EXP-A-SET.TXT    A-SET.TXT      > RESULT-A-SET.TXT 
BBTEST EXPECTED\EXP-A-DEGREE.TXT  A-DEGREE.TXT   > RESULT-A-DEGREE.TXT
BBTEST EXPECTED\EXP-A-LIST.TXT    A-LIST.TXT     > RESULT-A-LIST.TXT
BBTEST EXPECTED\EXP-A-MATRIX.TXT  A-MATRIX.TXT   > RESULT-A-MATRIX.TXT
BBTEST EXPECTED\EXP-A-BFS.TXT     A-BFS.TXT      > RESULT-A-BFS.TXT
BBTEST EXPECTED\EXP-A-DFS.TXT     A-DFS.TXT      > RESULT-A-DFS.TXT


: do a diff test 
ECHO ON
LDIFF EXPECTED\EXP-A-SET.TXT    A-SET.TXT
DIFF EXPECTED\EXP-A-DEGREE.TXT  A-DEGREE.TXT
DIFF EXPECTED\EXP-A-LIST.TXT    A-LIST.TXT
DIFF EXPECTED\EXP-A-MATRIX.TXT  A-MATRIX.TXT
DIFF EXPECTED\EXP-A-BFS.TXT     A-BFS.TXT
DIFF EXPECTED\EXP-A-DFS.TXT     A-DFS.TXT

PROMPT

