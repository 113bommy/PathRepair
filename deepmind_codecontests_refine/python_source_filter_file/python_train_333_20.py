import sys, math
input = sys.stdin.readline
 
def getInt(): return int(input())
def getVars(): return map(int, input().split())
def getList(): return list(map(int, input().split()))
def getStr(): return input().strip()
## -------------------------------

n, k = getVars()
a = getList()
d = {}
for x in a:
    x2 = x
    num = 0
    while x2 > 1:
        if x2 not in d:
            d[x2] = []
        d[x2].append(num)
        x2 //= 2
        num += 1
minS = -1
for key in d:
    if len(d[key]) >= k:
        dKey = d[key].copy()
        dKey.sort()
        s = sum(dKey[:k])
        if minS == -1:
            minS = s
        else:
            minS = min(minS, s)
print(minS)

'''
maxA = max(a)
d = {}
for i in range(n):
    if a[i] not in d:
        d[a[i]] = 0
    d[a[i]] += 1
    if d[a[i]] == k:
        exit(print(0))
print(d)
a = list(d.keys())
num = 0
while maxA > 1:
    num += 1
    print('maxA=', maxA, 'num=', num)
    d2 = {}
    for x in a:
        if x == 1: continue
        if x > maxA: break
        print('x=', x)
        a2 = x // 2
        if a2 not in d2:
            d2[a2] = 0
        if a2 in d:
            d2[a2] += d[a2]
        d2[a2] += d[x]
        if d2[a2] >= k:
            print(d2)
            exit(print(num))
    a = list(d.keys())
    maxA //= 2
    d = d2.copy()
    print(d)
'''
