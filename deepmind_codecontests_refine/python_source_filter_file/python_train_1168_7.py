import sys, collections, math, itertools, random, bisect
INF = sys.maxsize
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def input(): return sys.stdin.readline().strip()
mod = int(1e9+7)

for _ in range(int(input())):
    a,b,p = get_ints()
    s = input()
    sz = len(s)
    sum = 0
    while sum <= p and sz >= 0:
        sz -= 1
        if sz == len(s)-1 or s[sz-1] != s[sz]:
            if s[sz-1] == 'A':
                sum += a
            else:
                sum += b
    print(sz+1)