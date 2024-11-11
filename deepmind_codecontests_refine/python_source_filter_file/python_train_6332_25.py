from collections import deque
N,M=map(int,input().split())
p=list(map(int,input().split()))
fromto=[]
tree=[[] for _ in range(N)]
for i in range(N):
    fromto.append([i,p[i]-1])
cnt=0
for i in range(M):
    x,y=map(int,input().split())
    tree[x-1].append(y-1)
    tree[y-1].append(x-1)
col=[-1]*N
for i in range(N):
    if col[i]==-1:
        d = deque()
        d.append(i)
        while len(d)>0:
            v=d.popleft()
            col[v]=i
            for j in tree[v]:
                if col[j]==-1:
                    d.append(j)
            #print(col,d)
            #input()
#print(col,fromto)
for i in range(N):
    x=fromto[i][0]
    y=fromto[i][1]
    if col[x-1]==col[y-1]:
        cnt=cnt+1
print(cnt)
