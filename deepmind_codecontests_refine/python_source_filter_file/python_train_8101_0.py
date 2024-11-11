import sys

input=sys.stdin.readline
sys.setrecursionlimit(2*10**5)

n=int(input())
edge=[[] for i in range(n)]
for i in range(n-1):
    v,w=map(int,input().split())
    edge[v-1].append(w-1)
    edge[w-1].append(v-1)

if n==2:
    exit(print(1,2))

leafcnt=[0]*n
for v in range(n):
    for nv in edge[v]:
        if len(edge[nv])==1:
            leafcnt[v]+=1

used=[False]*n
line=[]
def line_check(v):
    used[v]=True
    line.append(leafcnt[v])
    flag=False
    for nv in edge[v]:
        if not used[nv] and len(edge[nv])!=1:
            if not flag:
                line_check(nv)
                flag=True
            else:
                return False
    return True

for v in range(n):
    if not used[v] and len(edge[v])==1+leafcnt[v] and len(edge[v])!=1:
        if not line:
            check=line_check(v)
            if not check:
                exit(print(-1))
        else:
            exit(print(-1))


line_rev=line[::-1]
res=min(line,line_rev)

res=[0]+res+[0]
res[1]-=1
res[-2]-=1

ans=[]
L=1
for val in res:
    R=L+val
    for i in range(L+1,R+1):
        ans.append(i)
    ans.append(L)
    L=R+1

print(*ans)
