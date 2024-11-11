'''
                ___                       ____                     
  ____ _____ _____/ (_)_  ______  ____ _____/ / /_  __  ______ ___  __
 / __ `/ __ `/ __  / / / / / __ \/ __ `/ __  / __ \/ / / / __ `/ / / /
/ /_/ / /_/ / /_/ / / /_/ / /_/ / /_/ / /_/ / / / / /_/ / /_/ / /_/ / 
\__,_/\__,_/\__,_/_/\__,_/ .___/\__,_/\__,_/_/ /_/\__, /\__,_/\__, /  
                        /_/                      /____/      /____/   
'''
import os.path
from math import gcd, floor, ceil
from collections import *
import sys
mod = 1000000007
INF = float('inf')
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")


if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve():
    def check(ans):
        n = len(ans)
        for i in range(n):
            for j in range(i, n):
                p = ans[i:j+1]
                c = 0
                size = j - i + 1
                for x in range(n-size+1):
                    if ans[x:x+size] == p:
                        c += 1
                if c % 2 == 0:
                    print(p, c)
                    return
    n = inp()
    if n == 1:
        ans = 'a'
    if n % 2 == 0:
        ans = n//2*'a' + 'b' + (n//2-1)*'a'
    else:
        ans = n//2*'a' + 'b' + (n//2-1)*'a'+'c'
    # check(ans)
    pr(ans)


for _ in range(inp()):
    solve()
