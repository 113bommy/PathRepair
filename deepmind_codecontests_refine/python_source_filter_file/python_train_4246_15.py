N,M=map(int,input().split())
friend=[[] for _ in range(N)]
for i in range(M):
    A,B=map(int,input().split())
    friend[A-1].append(B-1)
    friend[B-1].append(A-1)
ans=0
ischecked=[0]*N
for i in range(N):
    if ischecked[i]==1:
        continue
    group=1
    ischecked[i]=1
    ship=friend[i]
    while ship:
        nex=ship.pop(0)
        if ischecked[nex]==1:
            continue
        ischecked[nex]=1
        group+=1
        ship.extend(friend[nex])
    ans=max(ans,group)
print(ans)