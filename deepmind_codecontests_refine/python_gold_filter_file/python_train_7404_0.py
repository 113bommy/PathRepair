from collections import defaultdict, deque
from math import ceil

n, m = map(int, input().split())

graph = defaultdict(list)

for i in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

vis = set()
diams = []
for node in range(1, n + 1):
    if node not in vis:
        #print('node: ', node)
        vis.add(node)
        q = deque()
        cur_big = 0
        cur_big_node = node
        q.append((node, node, 0))
        while q:
            pro_n, par, val = q.popleft()
            for child in graph[pro_n]:
                if child != par:
                    vis.add(child)
                    q.append((child, pro_n, val + 1))

            if val > cur_big:
                cur_big = val
                cur_big_node = pro_n
        diameter = 0
        end_node = cur_big_node
        q.append((cur_big_node, cur_big_node, 0))
        pa = defaultdict(int)
        while q:
            pro_n, par, val = q.popleft()
            pa[pro_n] = par
            for child in graph[pro_n]:
                if child != par:
                    q.append((child, pro_n, val + 1))

            if val > diameter:
                diameter = val
                end_node = pro_n

        cen_node = end_node
        for i in range(diameter//2):
            cen_node = pa[cen_node]
        diams.append((diameter, cen_node))

diams.sort(reverse=True)
if len(diams) > 2:
    if diams[0][0] == diams[1][0] == diams[2][0]:
        res = ceil(diams[0][0]/2) + ceil(diams[1][0]/2) + 2
    else:
        res = max(diams[0][0], ceil(diams[0][0]/2) + ceil(diams[1][0]/2) + 1)
elif len(diams) >= 2:
    res = max(diams[0][0], ceil(diams[0][0]/2) + ceil(diams[1][0]/2) + 1)
else:
    res = diams[0][0]
print(res)
for i in range(1,len(diams)):
    print(diams[0][1], diams[i][1])
