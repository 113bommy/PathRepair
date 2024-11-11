n,k,s,t=map(int,input().split())
m=[set() for i in range(n+1)]
for i in range(k):
    a,b=map(int,input().split())
    m[a].add(b)
    m[b].add(a)
forw=[-1]*(n+1)
back=forw.copy()
take,push=[],[s]
forw[s]=0
way=0
z=0
while push:
    way+=1
    take,push=push,take
    while take:
        a=take.pop()
        if a==t and not z:
            z=way
        for x in m[a]:
            if forw[x]==-1:
                forw[x]=way
                push.append(x)
take,push=[],[t]
back[t]=0
way=0
while push:
    way+=1
    take,push=push,take
    while take:
        a=take.pop()
        for x in m[a]:
            if back[x]==-1:
                back[x]=way
                push.append(x)
ans=0
for i in range(1,n+1):
    for j in range(i+1,n+1):
        if j not in m[i] and max(forw[j]+back[i],forw[i]+back[j])+1>=z:
            ans+=1
print(ans)