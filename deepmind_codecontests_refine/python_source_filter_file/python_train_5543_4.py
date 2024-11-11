import math
n,k=map(int,input().split())
m=list(map(int,input().split()))
c=list(map(int,input().split()))
m.sort()
ans=0
for i in range(n-1,-1,-1):
    sw=min(i,k-1)
    ans=max(ans,math.ceil((n-i)/c[sw]))
res=[[] for _ in range(ans)]
for i in range(n):
    res[i%ans].append(m[i])
print(ans)
for i in range(ans):
    print(len(res[i]),*res[i])
