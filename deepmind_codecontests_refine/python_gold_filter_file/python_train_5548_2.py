from sys import stdin
from math import inf

input = lambda: stdin.readline().strip()
ipnut = input
def dist(a,b):
    return abs(a[0]-b[0])+abs(a[1]-b[1])<=k
for i in range(int(input())):
    n = int(input())
    # n,k = map(int,ipnut().split())
    # d = list(map(int,input().split()))
    o,t,th = 0,0,0
    lox = []
    for i in range(n):
        m = list(input())
        lox.append(m)
        for j in range(n):
            if (i+j)%3==0:
                o+=m[j]=='X'
            elif (i + j) % 3 == 1:
                t += m[j] == 'X'
            else:
                th+=m[j]=='X'
    mod = 0
    if min(o,t,th)==o:
        mod = 0
    elif min(o,t,th)==t:
        mod = 1
    else:
        mod = 2
    for i in range(n):
        an = []
        for j in range(n):
            if (i+j)%3==mod:
                if lox[i][j]==".":
                    an.append(lox[i][j])
                else:
                    an.append("O")
            else:
                an.append(lox[i][j])
        print(''.join(an))