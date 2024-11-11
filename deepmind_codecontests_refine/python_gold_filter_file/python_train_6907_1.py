# Recursion be damned
# Unfortunately, given that python's heapq doesn't have an update function
# this isn't memory efficient 
import heapq as hp
def search(target ,queue, graph):
    global visited
    while len(queue):
        v = hp.heappop(queue)
        visited.add(v[2])
        d = v[0]
        for n in graph[v[2]]:
            if n[1] not in visited:
                if d + n[0] < path[n[1]-1][0]:
                    path[n[1]-1] = (d + n[0] ,v[2], n[1])
                    hp.heappush(queue,path[n[1]-1])
        if v[2] == target: return
nodes,m = map(int,input().split())
visited,g = set(),{}
path = [(1000000000000,0,0)]*nodes;
q = [(0,1,1)]; hp.heapify(q)
for _ in range(m):
    a,b,c = map(int,input().split())
    if a not in g: g.update({a:[(c,b)]})
    else: g[a].append((c,b))
    if b not in g: g.update({b:[(c,a)]})
    else: g[b].append((c,a))
if nodes in g:
    search(nodes,q,g)
    if path[nodes-1][2] == 0: print(-1); exit()
    ans = [nodes]
    while (nodes!=1):
        nodes = path[nodes-1][1]
        ans.append(nodes)
    ans.reverse()
    print(*ans)
else: print(-1)