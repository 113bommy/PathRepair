import sys
from sys import stdin

tt = 1

for loop in range(tt):

    n,m = map(int,stdin.readline().split())

    a = [list(map(int,stdin.readline().split())) for i in range(n)]

    b = [[None] * m for i in range(n)]

    for i in range(n):
        for j in range(m):

            if (i+j)%2 == 0:
                b[i][j] = 30030
            else:
                b[i][j] = 30030 + a[i][j]**4

    for i in b:
        print (*i)