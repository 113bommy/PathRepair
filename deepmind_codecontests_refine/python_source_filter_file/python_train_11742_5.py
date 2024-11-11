#!python3

class Node:
    
    def __init__(self, num):
        self.num = num
        self.depth = 0
        self.parent = (None, None)


LI = lambda: list(map(int, input().split()))

# input
N = int(input())
AB = [LI() for _ in range(N - 1)]
M = int(input())
UV = [LI() for _ in range(M)]

# params
links = [[] for _ in range(N)]
nodes = [Node(i) for i in range(N)]
w = []
p2 = [2 ** i for i in range(N + 1)]


def create_links():
    for i in range(N - 1):
        a, b = AB[i][0] - 1, AB[i][1] - 1
        links[a].append((b, i))
        links[b].append((a, i))


def create_tree(v, p=-1):
    for u, i in links[v]:
        if u == p:
            continue
        nodes[u].parent = (nodes[v], i)
        nodes[u].depth = nodes[v].depth + 1
        create_tree(u, v)


def between_links(s, t):
    x = nodes[s]
    y = nodes[t]
    if x.depth > y.depth:
        x, y = y, x
    s = set()
    while x.depth < y.depth:
        y, i = y.parent
        s.add(i)
    while x is not y:
        x, i = x.parent
        y, j = y.parent
        s.add(i)
        s.add(j)
    return s


def create_between_links():
    for u, v in UV:
        s = between_links(u - 1, v - 1)
        w.append(s)


def main():
    create_links()
    create_tree(0)
    create_between_links()
    
    ans = 0
    n = p2[M]
    for i in range(n):
        f = 0
        s = set()
        for j in range(M):
            if i >> j & 1:
                f += 1
                s |= w[j]
        v = p2[N - 1 - len(s)]
        if f % 2 == 0:
            ans += v
        else:
            ans -= v
    print(ans)

    
if __name__ == "__main__":
    main()
