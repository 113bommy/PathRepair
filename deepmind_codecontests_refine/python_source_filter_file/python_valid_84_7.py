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

def solve():pass

for _ in range(int(input())):
    n,k = get_int()
    if n == 1:
        print(k)
    else:
        print((k//((n-(n//2))+1)) if not n % 2 else (k//((n-(n//2)+1))+1))