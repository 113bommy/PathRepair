from math import *

n = int(input())
a = [int(i) for i in input().split()]
INF = 1000000
d = {}
for i in range(n):
    div = 2
    s = a[i]
    while div*div <= a[i]:
        cnt = 0
        while s % div == 0:
            s //= div
            cnt += 1
        if cnt > 0:
            if div not in d:
                d[div] = []
            d[div].append(cnt)
        div += 1
    if s > 1:
        if s not in d:
            d[s] = []
        d[s].append(1)
#print(d)
ans = 1
for i in d:
    if len(d[i]) >= n - 2:
        mi1 = INF
        mi2 = INF
        for x in d[i]:
            if x <= mi1:
                mi2 = mi1
                mi1 = x
            elif x <= mi2:
                mi2 = x
        if mi2 < INF and len(d[i]) == n:
            ans *= i**mi2
        else:
            ans *= i**mi1
            
    
print(ans)
