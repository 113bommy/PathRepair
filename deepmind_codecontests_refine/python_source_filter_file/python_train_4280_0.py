#!/usr/bin/env python3

n, m = map(int, input().rstrip().split())
adj = [[] for i in range(n+1)]

for i in range(m):
    u, v = map(int, input().rstrip().split())
    adj[u].append(v)
    adj[v].append(u)

vis = [False for i in range(n+1)]
ring = [None for i in range(n+1)]
ring_start = None
vis_cnt = 0


def dfs(cur, par):
    vis[cur] = True
    global vis_cnt, ring_start
    vis_cnt += 1
    found_start = []
    for nxt in adj[cur]:
        if nxt == par:
            continue
        if vis[nxt]:
            if ring[nxt] != cur:
                found_start.append(nxt)
        else:
            tmp = dfs(nxt, cur)
            if tmp:
                found_start.append(tmp)

    if len(found_start) != 1:
        return None

    ring[cur] = found_start[0]
    if found_start[0] == cur:
        ring_start = cur
        return None
    return found_start[0]


dfs(1, -1)

if not ring_start or vis_cnt == 0:
    print("NO")
else:
    print("FHTAGN!")
