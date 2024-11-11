from collections import defaultdict
from operator import itemgetter
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

ans = 1000
for n in range(2**N):
    n = bin(n)[2:]
    if n.count('1')%2!=0:
        continue
    n = '0'*(N-len(n))+n
    l = []
    for i in range(N):
        if n[i]=='0':
            l.append([A[i],i])
        else:
            l.append([B[i],i+1])
    inversion = 0
    for i in range(N):
        if inversion>=ans:
            break
        for j in range(i+1,N):
            if l[i][0]>l[j][0]:
                inversion += 1
    if inversion>=ans:
        continue
    l.sort(key=itemgetter(0))
    d = defaultdict(list)
    for i in range(N):
        v,j = l[i]
        if (i-j)%2==1:
            d[v].append(i)
    possible = True
    for v in d:
        if len(d[v])%2==1:
            possible = False
        else:
            for i in range(len(d[v])//2):
                if (d[v][2*i+1]-d[v][2*i])%2==1:
                    inversion += d[v][2*i+1]-d[v][2*i]
                else:
                    possible = False
                    break
        if not possible:
            break
    if possible:
        ans = min(ans,inversion)

if ans == 1000:
    ans = -1
print(ans)