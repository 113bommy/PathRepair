import sys
from math import sqrt,ceil,floor,gcd
from collections import Counter

input = lambda:sys.stdin.readline()

def int_arr(): return list(map(int,input().split()))
def str_arr(): return list(map(str,input().split()))
def get_str(): return map(str,input().split())
def get_int(): return map(int,input().split())
def get_flo(): return map(float,input().split())
def lcm(a,b): return (a*b) // gcd(a,b)

mod = 1000000007

def solve(c,d):
    if abs(c-d) == 1:
        print(-1)
    else:
        if c == d and c == 0:
            print(0)
        elif c == d:
            print(1)
        elif c == 0 or d == 0:
            print(2)
        else:
            print(2)


for _ in range(int(input())):
    c,d = get_int()
    solve(c,d)