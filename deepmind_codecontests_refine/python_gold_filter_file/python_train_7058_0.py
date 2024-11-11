n=int(input())
g=[[] for i in range(n)]
ro=[0]*n
for i in range(n-1):
    a,b=map(int,input().split())
    ro[a-1]+=1
    ro[b-1]+=1
    g[a-1].append(b-1)
    g[b-1].append(a-1)
c=list(map(int,input().split()))
c.sort(reverse=True)
m=max(ro)
mi=ro.index(m)
q=[mi]
ans=[0]*n
v=[0]*n
v[mi]=1
ans[mi]=c.pop(0)
while len(q)>0:
    s=q.pop()
    for i in g[s]:
        if v[i]==0:
            v[i]=1
            ans[i]=c.pop(0)
            q.append(i)
print(sum(ans)-max(ans))
print(*ans)
