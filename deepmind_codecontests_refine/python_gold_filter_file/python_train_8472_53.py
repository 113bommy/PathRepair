#                               #
    # author : samars_diary #
    # 22:19:41 | 10-09-2020 #
#                               #

import sys, os.path, math

if(os.path.exists('input.txt')):
    sys.stdin = open('input.txt',"r")
    sys.stdout = open('output.txt',"w")

sys.setrecursionlimit(10 ** 5)

def i(): return sys.stdin.readline().strip()
def ii(): return int(sys.stdin.readline())
def li(): return list(sys.stdin.readline().strip())
def mii(): return map(int, sys.stdin.readline().split())
def lii(): return list(map(int, sys.stdin.readline().strip().split()))

#print=sys.stdout.write

def solve():
    a,b=mii()
    if (a%2)==0:
        if b<=(a//2):
            print(2*b-1)
        else:
            print(2*(b-(a//2)))
    else:
        if b<=((a//2)+1):
            print(2*b-1)
        else:
            print(2*(b-1-(a//2)))
solve()
