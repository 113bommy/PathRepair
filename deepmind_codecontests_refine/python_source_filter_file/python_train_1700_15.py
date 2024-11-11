import math 
from collections import Counter, defaultdict
import sys
import heapq
# resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
# sys.setrecursionlimit(10**6)

"""
# Template Designed By: Shivshanker Singh
# Note: If you find this template useful and want to use it then please don't just copy paste it 
        you can take ideas from this and make your own.
        because if you copy paste as it is then there are high chances that both of us will be plagiarized
        (because most of code will be same for small problems).
        So to avoid this please dont copy paste.
"""

mod       = 10**9 + 7
input     = sys.stdin.readline
readInt   = lambda : int(input().strip())
readfloat = lambda : float(input().strip())
readStr   = lambda : input().strip()
intList   = lambda : list(map(int, input().strip().split()))
intMap    = lambda : map(int, input().strip().split())
floatList = lambda : list(map(float, input().strip().split()))
floatMap  = lambda : map(float, input().strip().split())
strList   = lambda : list(input().strip().split())


def print(*args, end='\n', sep=' '):
    for i in args:
        sys.stdout.write(str(i))
        sys.stdout.write(sep)
    sys.stdout.write(end)


def solve():
    res = [10**6 for i in range(n)]
    d = dict()
    for i in range(k):
        d[arr[i]] = trr[i]
    if 1 in d:
        res[0] = d[1]

    for i in range(1, n):
        if i+1 not in d:
            res[i] = res[i-1] + 1
        else:
            res[i] = min(res[i-1]+1, d[i+1])
    
    if n in d:
        res[n-1] = min(res[n-1], d[n])
    for i in range(n-2, -1, -1):
        if i+1 not in d:
            res[i] = min(res[i], res[i+1]+1)
        else:
            res[i] = min([res[i], res[i+1]+1, d[i+1]])
    
    return res
    
# if __name__ == '__main__':
for _ in range(readInt()):
    input()
    n, k = intMap()
    arr = intList()
    trr = intList()
    
    # print('YES' if solve() else 'NO')
    print(*solve())