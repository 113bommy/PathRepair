n,m=map(int,input().split())
d=[list(map(int,input().split())) for _ in range(m)]
c=[list(map(int,input().split())) for _ in range(n)]
ans0=[0]
ans1=[0]
ans2=[0]
for k in range(1,m+1):
    a0=0
    a1=0
    a2=0
    for i in range(n):
        for j in range(n):
            if (i+j+2)%3==0:
                a0+=d[c[i][j]-1][k-1]
            elif (i+j+2)%3==1:
                a1+=d[c[i][j]-1][k-1]
            else:
                a2+=d[c[i][j]-1][k-1]
    ans0.append(a0)
    ans1.append(a1)
    ans2.append(a2)
ans=float("inf")
import itertools
for x,y,z in itertools.permutations(range(1,m+1)):
    ans=min(ans,ans0[x]+ans1[y]+ans2[z])

print(ans)
