import heapq
n,k=map(int,input().split())
z=[0,1]
for i in range(1,n):
    z.append(z[i]+2)
s=sorted([list(map(int,input().split()))for _ in range(n)],key=lambda x:-x[1])
q=[]
v=0
ans=0
l=[0]*-~n
for a in s[:k]:
    if not l[a[0]]:
        v+=1
        ans+=z[v]
    else:
        heapq.heappush(q,a[1])
    l[a[0]]=1
    ans+=a[1]
tem=ans
for a in s[k:]:
    if not q:break
    if l[a[0]]:continue
    l[a[0]]=1
    v+=1
    t=heapq.heappop(q)
    tem=tem-t+a[1]+z[v]
    ans=max(ans,tem)
print(tem)