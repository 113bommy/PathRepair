from collections import defaultdict
from math import gcd
from os import path, truncate
from sys import int_info, stdin, stdout
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

for _ in range(gi()):
    w,h=map(int,input().split())
    xw=list(map(int,input().split()))
    xwh = list(map(int, input().split()))
    yh = list(map(int, input().split()))
    yhw = list(map(int, input().split()))
    a=(xw[-1]-xw[1])*h
    b=(xwh[-1]-xw[1])*h
    c=(yh[-1]-yh[1])*w
    d=(yhw[-1]-yhw[1])*w
    ab=max(a,b)
    cd=max(c,d)
    print(max(ab,cd))