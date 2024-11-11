N=int(input())
F=[int(input().replace(' ',''),2) for _ in range(N)]
P=[list(map(int,input(),split())) for _ in range(N)]

ans=-10**10
for i in range(1,1<<10):
    prof=0
    for j,f in enumerate(F):
        prof+=P[j][bin(i&f).count("1")]
    ans=max(ans,prof)

print(ans)