from collections import defaultdict

get= lambda : map(int,input().split())
n,m=get()
c=list(get())
adj={ i:set() for i in set(c)}
for i in range(m):
    a,b=get()
    if c[a-1]!=c[b-1]:
        adj[c[b-1]].add(c[a-1])
        adj[c[a-1]].add(c[b-1])

print(max(adj,key=lambda x:len(adj[x])))
    
    
# http://codeforces.com/problemset/problem/246/D
