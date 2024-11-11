from sys import stdin

def put(): return map(int, stdin.readline().split())

def dfs():
    s = [(1,0)]
    vis = [0]*(n+1)
    while s:
        i,p = s.pop()
        if vis[i]==0:
            vis[i]=1
            parent[i]=p
            alice[i]=alice[p]+1
            s.append((i,p))
            for j in tree[i]:
                if j!=p:
                    s.append((j,i))
        elif vis[i]==1:
            vis[i]=2
            for j in tree[i]:
                if j != p:
                    depth[i]= max(depth[i], depth[j]+1)        




n,k = put()
tree = [[] for i in range(n+1)]
alice, depth, parent = [0]*(n+1), [0]*(n+1), [0]*(n+1)
for _ in range(n-1):
    x,y = put()
    tree[x].append(y)
    tree[y].append(x)
dfs()
ans = 0
i = x
time = 1
while i!=0:
    if time<alice[i]:
        ans = max(ans, alice[i]+depth[i])
    i = parent[i]
    time+=1

print(2*ans-2)