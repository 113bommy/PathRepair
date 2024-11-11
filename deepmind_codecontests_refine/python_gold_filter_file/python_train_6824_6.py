n=int(input())
c=[int(i) for i in input().split()]
a=[input() for i in range(n)]
inf=[[10**15,10**15] for i in range(n)]
inf[0][0]=0; inf[0][1]=c[0]
def howMany(i):
    inf[i][0]=min(inf[i-1][0] if a[i]>=a[i-1] else 10**15,
            inf[i-1][1] if a[i]>=a[i-1][::-1] else 10**15)
    inf[i][1]=min(inf[i-1][0]+c[i] if a[i][::-1]>=a[i-1] else 10**15,
            inf[i-1][1]+c[i] if a[i][::-1]>=a[i-1][::-1] else 10**15)
for j in range(1,n):
    howMany(j)
ans=min(inf[n-1][0],inf[n-1][1])
if ans>=10**15: print(-1)
else: print(ans)