n=int(input())
w=[[] for i in range(n)]
for i in range(n):
    a=int(input())
    for j in range(a):
        x,y=map(int,input().split())
        w[i].append((x,y))
ans=0
for i in range(1<<n):
    x="0"*15+bin(i)[2:]
    z=[int(i) for i in x[-n:]]
    f=1
    for p,q in enumerate(w):
        if z[p]==1:
            for r in q:
                if (z[r[0]-1]!=r[1]):
                    f=0
    if f:
        ans=max(ans,z.count('1'))
print(ans)