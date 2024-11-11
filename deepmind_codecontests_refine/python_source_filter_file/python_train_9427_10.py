n,k=map(int,input().split())
l=[input() for _ in range(n)]
imp=input()
d={}
for x in l:
    t=len(x)
    d[t]=d.get(t,0)+1
leimp=len(imp)
leimpc=d[leimp]
ans=0
for x in d:
    if x<leimp: ans+=d[x]
ansl=ans+leimpc
print(ans+1+(ans//k*5),ansl++(ansl//k*5))