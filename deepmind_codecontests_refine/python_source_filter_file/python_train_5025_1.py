# if da > db then Alice wins
# if dist(a, b) <= da then Alice wins
# if da+da >= db then Alice wins because Bob can't jump over Alice
# and go to some other branch of tree
# otherwise is there always an element at more than 2*da away?

import sys
input = iter(sys.stdin.read().splitlines()).__next__

def furthest(graph, source):
    S = [(source, 0)]
    furthest_node = source
    furthest_dist = 0
    discovered = [False]*len(graph)
    while S:
        u, dist = S.pop()
        if dist > furthest_dist:
            furthest_node = u
            furthest_dist = dist
        if discovered[u]:
            continue
        discovered[u] = True
        for v in graph[u]:
            S.append((v, dist+1))
    return furthest_node, furthest_dist

def distance(graph, source, dest):
    S = [(source, 0)]
    discovered = set()
    while S:
        u, dist = S.pop()
        if u == dest:
            return dist
        if u in discovered:
            continue
        discovered.add(u)
        for v in graph[u]:
            S.append((v, dist+1))

t = int(input())
ans = []
for _ in range(t):
    n, a, b, da, db = map(int, input().split())
    if da+da >= db:
        for edge in range(n-1):
            input()
        print('Alice')
        continue
    graph = [[] for node in range(n)]
    for edge in range(n-1):
        u, v = [int(i)-1 for i in input().split()]
        graph[u].append(v)
        graph[v].append(u)
    if distance(graph, a-1, b-1) <= da:
        ans.append('Alice')
        continue
    diameter = furthest(graph, furthest(graph, 0)[0])[1]
    if da+da >= diameter:
        ans.append('Alice')
    else:
        ans.append('Bob')
print(*ans, sep='\n')