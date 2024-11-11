# -*- coding: utf-8 -*-
"""
Created on Fri Mar  6 15:16:36 2020

@author: akprasad

B. President's Office
time limit per test: 2 seconds
memory limit per test: 64 megabytes
input: standard input
output: standard output

President of Berland has a very vast office-room, where,
apart from him, work his subordinates. Each subordinate,
as well as President himself, has his own desk of a unique colour.
Each desk is rectangular, and its sides are parallel to the office walls.
One day President decided to establish an assembly, of which all his
deputies will be members. Unfortunately, he does not remember the exact
amount of his deputies, but he remembers that the desk of each his deputy
is adjacent to his own desk, that is to say, the two desks (President's and
each deputy's) have a common side of a positive length.

The office-room plan can be viewed as a matrix with n rows and m columns.
Each cell of this matrix is either empty, or contains a part of a desk.
An uppercase Latin letter stands for each desk colour.
The «period» character («.») stands for an empty cell.

Input
The first line contains two separated by a space integer numbers
n, m (1 ≤ n, m ≤ 100) — the length and the width of the office-room,
and c character — the President's desk colour. The following n lines
contain m characters each — the office-room description. It is guaranteed
that the colour of each desk is unique, and each desk represents a
continuous subrectangle of the given matrix. All colours are marked
by uppercase Latin letters.

Output
Print the only number — the amount of President's deputies.

Examples

input
3 4 R
G.B.
.RR.
TTT.
output
2

input
3 3 Z
...
.H.
..Z
output
0

"""

if __name__ == '__main__':
    neighbours = set()
    n, m, c = input().split()
    n, m = int(n), int(m)
    matrix = []
    for _ in range(n):
        matrix.append(input())
    
    pm = []  # padded matrix
    pm.append("." * (m + 2))
    for e in matrix:
        pm.append("." + e + ".")
    pm.append("." * (m + 2))

    # iterate over the elements of the matrix
    forbidden = [".", c]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if pm[i][j] == c:
                if pm[i + 1][j] not in forbidden:
                    neighbours.add(pm[i + 1][j])
                if pm[i - 1][j] not in forbidden:
                    neighbours.add(pm[i - 1][j])
                if pm[i][j + 1] not in forbidden:
                    neighbours.add(pm[i][j + 1])
                if pm[i][j - 1] not in forbidden:
                    neighbours.add(pm[i][j - 1])
    print(len(neighbours))
