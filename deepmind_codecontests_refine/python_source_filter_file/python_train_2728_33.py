import sys
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
    res = 'NO'
    for i in range(n-1):
        if abs(a[i] - a[i+1]) > 2:
            res = 'YES'
            res2 = [i+1, i+2]
    print(res)
    if res == 'YES':
        print(*res2)

