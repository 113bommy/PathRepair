n, m = map(int, input().split())
A = list(map(int, input().split()))
LR = []
for i in range(m):
    l, r = map(int, input().split())
    l, r = l-1, r-1
    LR.append((l, r))

#print()
from itertools import accumulate
ans = -float('inf')
subs = -1
for i in range(n):
    a = A[i]
    imos = [0]*(n+1)
    s = []
    for j in range(m):
        l, r = LR[j]
        if l <= i and i <= r:
            continue
        else:
            imos[l] += 1
            imos[r+1] += 1
            s.append(j+1)
    imos = list(accumulate(imos))
    B = [0]*n
    for k in range(n):
        B[k] = A[k]-imos[k]
    min_ = min(B)
    temp = a-min_
    #print(i, temp, subs)
    if temp >= ans:
        ans = temp
        subs = tuple(s)
print(ans)
print(len(subs))
print(*subs)
