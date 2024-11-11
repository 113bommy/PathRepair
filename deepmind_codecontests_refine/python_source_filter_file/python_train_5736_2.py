n,m= map(int, input().split())
P = list(map(int, input().split()))

for i in range(n):
    if P[i] == m:
        break

LD = [0]*(i+1)
LU = [0]*(i+1)
for j in range(i):
    LD[j+1] = LD[j]
    LU[j+1] = LU[j]
    if P[i-1-j] < m:
        LD[j+1] += 1
    else:
        LU[j+1] += 1

RD = [0]*(n-i)
RU = [0]*(n-i)
for j in range(n-1-i):
    RD[j+1] = RD[j]
    RU[j+1] = RU[j]
    if P[i+1+j] < m:
        RD[j+1] += 1
    else:
        RU[j+1] += 1

#print(RU)
#print(RD)
from collections import defaultdict
de = defaultdict(lambda:0)
do = defaultdict(lambda:0)
for k in range(n-i):
    if k%2 == 0:
        u = k-2*RU[k]
        d = k-2*RD[k]
        de[(u, d)] += 1
    else:
        u = k-2*RU[k]
        d = k-2*RD[k]
        do[(u, d)] += 1
#print(de)
#print(do)
ans = 0
for j in range(i+1):
    if j%2 == 0:
        u = 2*LU[j]-j
        d = 2*LD[j]-j
        #print(j, u, d)
        ans += de[(u, d)]
        u = 2*LU[j]-j-1
        d = 2*LD[j]-j+1
        #print(j, u, d)
        ans += do[(u, d)]
    else:
        u = 2*LU[j]-j
        d = 2*LD[j]-j
        #print(j, u, d)
        ans += do[(u, d)]
        u = 2*LU[j]-j-1
        d = 2*LD[j]-j+1
        #print(j, u, d)
        ans += do[(u, d)]
print(ans)
