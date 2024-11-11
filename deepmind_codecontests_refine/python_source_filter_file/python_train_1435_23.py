N,M=map(int,input().split())
G=[]
for i in range(0,M):
    G.append([])

for i in range(0,M):
    a,b=map(int,input().split())
    a-=1
    b-=1
    G[a].append(b)
    G[b].append(a)

q=[]
sign=[-1]*N
sign[0]=0
q.append(0)
while q:
    x=q.pop(0)
    for nv in G[x]:
        if sign[nv]==-1:
            sign[nv]=x
            q.append(nv)

print("Yes")
for i in range(1,N):
    print(sign[i]+1)
