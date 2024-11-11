n = int(input())
q = list(map(int,input().split()))
z = 0; u = 0
for i in q:
    u += i
    z = max(z,-u)
u = z+1
p = [u]
for i in q:
    u += i
    p.append(u)
q = [1 for g in range(n)]
if max(p) > n or min(p) < 1: print(-1); exit(0)
for i in p:
    if q[i-1]:
        print(-1)
        exit(0)
    q[i-1] = 1
for i in p: print(i,end=' ')