from sys import stdin, stdout
from collections import deque

T = int(stdin.readline().strip())
out = []

for _ in range(T):
    n,m,a,b = stdin.readline().split()
    n,m = int(n),int(m)
    roads = {}
    for _ in range(m):
        x,y = stdin.readline().split()
        roads.setdefault(x,[]).append(y)
        roads.setdefault(y,[]).append(x)

    visited = set([a])
    counta, ignore = 0, 0

    for aa in roads[a]:
        if aa not in visited:
            next = deque([aa])
            flg, c = True, 0
            while next:
                v1 = next.popleft()
                if v1 == b:
                    flg = False
                    continue
                if v1 in visited:
                    continue
                visited.add(v1)
                for v2 in filter(lambda x : x not in visited, roads[v1]):
                    next.appendleft(v2)
                c+=1
            if flg:
                counta += c
            else:
                ignore += c

    out.append("{}\n".format(counta * (n-2-counta-ignore)))

stdout.writelines(out)
