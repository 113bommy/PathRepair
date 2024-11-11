import sys, math
input = sys.stdin.readline

def getInt(): return int(input())
def getVars(): return map(int, input().split())
def getList(): return list(map(int, input().split()))
def getStr(): return input().strip()
## -------------------------------

t = getInt()
for _ in range(t):
    n = getInt()
    a = getList()
    m = a[n-1]+1
    res = 0
    for i in range(n-1, -1, -1):
        if a[i] < m :
            m = a[i]
        else:
            res += 1
    print(res)
