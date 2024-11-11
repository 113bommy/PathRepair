n,m=map(int,input().split())
r=[[] for x in range(n)]
for c in range(m):
    a,b=map(int,input().split())
    r[a-1].append(b-1)
    r[b-1].append(a-1)
s=[-1]*n
u=[0]
k=1
for c in range(10**5):
    v=[]
    for d in u:
        for e in r[d]:
            if s[e]==-1:
                s[e]=d
                k+=1
                v.append(e)
    if k>n-1:
        break
    u=v
print('Yes')
for c in s[1:]:
    print(c+1)