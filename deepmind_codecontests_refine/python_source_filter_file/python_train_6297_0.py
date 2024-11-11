from sys import stdin, stdout
import sys


class Node(object):
    def __init__(self, label):
        self.label = label
        self.par = self
        self.rank = 0


class DisjointSet(object):
    def __init__(self, n):
        self.n = n
        self.nodes = [Node(i) for i in range(self.n)]

    def find(self, u):
        if u == u.par:
            return u
        return self.find(u.par)

    def union(self, u, v):
        u, v = self.find(u), self.find(v)
        if u == v:
            return False
        if u.rank > v.rank:
            u, v = v, u
        u.par = v
        if u.rank == v.rank:
            v.rank += 1
        return True

    def size(self):
        cnt = 0
        for node in self.nodes:
            if node.par == node:
                cnt += 1
        return cnt


def color(adj, colors, root):
    neighbor_color = 1 - colors[root]

    for neighbor in adj[root]:
        if colors[neighbor] == -1:
            colors[neighbor] = neighbor_color
            if color(adj, colors, neighbor):
                pass
            else:
                return False
        else:
            if colors[neighbor] != neighbor_color:
                return False

    return True


if __name__ == "__main__":
    try:
        print(sys.setrecursionlimit(10000))
        mod = 1000000007

        n, m = map(int, input().split())

        dsu = DisjointSet(n)

        reds = []

        for _ in range(m):
            a, b, c = map(int, input().split())
            if c == 0:
                reds.append((a - 1, b - 1))
            else:
                dsu.union(dsu.nodes[a - 1], dsu.nodes[b - 1])

        new_graph = {}
        cnt = 0
        for i in range(n):
            comp = dsu.find(dsu.nodes[i])
            if comp.label not in new_graph.keys():
                new_graph[comp.label] = cnt
                cnt += 1

        x = len(new_graph)
        assert cnt == x
        dsu2 = DisjointSet(x)
        adj = [[] for _ in range(x)]
        colors = [-1 for _ in range(x)]

        for a, b in reds:
            comp1 = dsu.find(dsu.nodes[a]).label
            comp2 = dsu.find(dsu.nodes[b]).label

            if comp1 == comp2:
                print(0)
                exit(0)
            else:
                index1 = new_graph[comp1]
                index2 = new_graph[comp2]

                if index1 >= x or index2 >= x:
                    print(-1)
                    exit(0)

                dsu2.union(dsu2.nodes[index1], dsu2.nodes[index2])
                adj[index1].append(index2)
                adj[index2].append(index1)

        for i in range(x):
            if colors[i] == -1:
                colors[i] = 0
                ans = color(adj, colors, i)
                if ans:
                    pass
                else:
                    print(0)
                    exit(0)

        comps = dsu2.size()
        ans = 1

        for _ in range(comps - 1):
            ans *= 2
            ans %= mod
        print(ans)
        exit(0)
    except Exception as e:
        print(e)
        print(-1)
        exit(0)
