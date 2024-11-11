rip=[0]*(3001)

n,v=[int(x) for x in input().split()]

for _ in range(n):
    d,p=[int(x) for x in input().split()]
    rip[d]+=p
ans=0
for i in range(1,3001):
    t=min(v,rip[i-1]+rip[i])
    rip[i]=rip[i]-max(0,t-rip[i-1])
    ans+=t
print(ans)