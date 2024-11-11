import collections
N,M=map(int,input().split())
tree=[[] for _ in range(N)]
for _ in range(M):
    u,v=map(int,input().split())
    tree[u-1].append(v-1)
S,T=map(int,input().split())
s=S-1
t=T-1
ischecked=[[0]*3 for _ in range(N)]
ischecked[s][0]=1
ans=-1
q=collections.deque()
q.append([s,0])
while q:
    v,c=q.popleft()
    if v==t and c%3==0:
        ans=c//3
        break
    for i in tree[v]:
        if ischecked[i][(c+1)%3]==0:
            q.append([i,c+1])
            ischecked[i][(c+1)%3]==1
print(ans)