from sys import stdin, gettrace
from collections import deque

if gettrace():
    inputi = input
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()

def readGraph(n, m):
    adj = [set() for _ in range(n)]
    for _ in range(m):
        u,v = map(int, input().split())
        adj[u-1].add(v-1)
        adj[v-1].add(u-1)
    return adj


def main():
    n,m,k = map(int, inputi().split())
    adj = readGraph(n, m)
    parent = [-2] + [-1]*(n-1)
    ordered = []
    q = deque()
    q.append(0)
    depth = [0]*n
    while q:
        c =q.popleft()
        for a in adj[c]:
            if parent[a] != -1 and a != parent[c]:
                b1 = [a]
                b2 = [c]
                while parent[a] != parent[c]:
                    da = depth[a]
                    dc = depth[c]
                    if da >= dc:
                        a = parent[a]
                        b1.append(a)
                    if dc >= da:
                        c = parent[c]
                        b2.append(c)
                loop = b1 + [parent[a]] + b2[::-1]
                if len(loop) <= k:
                    print(2)
                    print(len(loop))
                    print(' '.join(map(lambda x:str(x+1), loop)))
                else:
                    print(1)
                    print(' '.join(map(lambda x:str(x+1), loop[0:k+1:2])))
                return
            elif parent[a] == -1:
                parent[a] = c
                q.append(a)
                depth[a] = depth[c] + 1
    # It is a tree
    g0 = [a for a in range(n) if depth[a]%2 == 0]
    g1 = [a for a in range(n) if depth[a]%2 == 1]
    if len(g0) >= (k+1)//2:
        g = g0
    else:
        g = g1
    print(1)
    print(' '.join(map(lambda x:str(x+1), g[:(k+1)//2])))







if __name__ == "__main__":
    main()