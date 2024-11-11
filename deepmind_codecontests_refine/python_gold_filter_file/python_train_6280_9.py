from os import path
from math import ceil
from sys import stdin, stdout
if path.exists('tc.txt'):
    stdin = open('tc.txt', 'r')
def gmi(): return map(int, stdin.readline().strip().split())
def gms(): return map(str, stdin.readline().strip().split())
def gari(): return list(map(int, stdin.readline().strip().split()))
def gart(): return tuple(map(int, stdin.readline().strip().split()))
def gars(): return list(map(str, stdin.readline().strip().split()))
def gs(): return stdin.readline().strip()
def gls(): return list(stdin.readline().strip())
def gi(): return int(stdin.readline())


tc = gi()

while tc:
    tc -= 1
    n, a, b = gmi()
    s = gs()

    temp = 1

    for i in range(1, n):
        if s[i] != s[i-1]:
            temp += 1

    if 0 <= b:
        ans = a*n + b*n
    else:
        ans = a*n + b*(temp//2 + 1)

    print(ans)













