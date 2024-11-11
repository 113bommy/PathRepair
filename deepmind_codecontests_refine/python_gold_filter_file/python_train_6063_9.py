from sys import stdin
from collections import defaultdict, deque

debug = False


def join(_s, _l):
    return _s.join(map(str, _l))


def read(_f=None):
    if _f == None:
        return stdin.readline().strip()
    return _f(stdin.readline().strip())


def readlist(_f=None):
    _l = stdin.readline().strip().split()
    if _f == None:
        return _l
    return map(_f, _l)


readint = lambda: read(int)
readints = lambda: readlist(int)
printval = lambda _r: print(_r, end=" ")
printline = lambda _s, _r: print(join(_s, _r), end="\n")

graph = defaultdict(list)
levels = defaultdict(list)


def get_height(depth):
    queue = deque()
    queue.append((0, -1))
    d = 0
    while queue:
        size = len(queue)
        for _ in range(size):
            node, parent = queue.popleft()
            depth[node] = d
            levels[d].append(node)
            for neigh in graph[node]:
                if neigh != parent:
                    queue.append((neigh, node))
        d += 1
    return d


def paths(max_depth, depth, priority):
    for d in range(max_depth, -1, -1):
        for node in levels[d]:
            for parent in graph[node]:
                if depth[node] > depth[parent]:
                    priority[parent] += priority[node] + 1


def solve():
    n, k = readints()

    if k >= n:
        return 0

    for _ in range(n - 1):
        u, v = readlist(lambda x: int(x) - 1)
        graph[u].append(v)
        graph[v].append(u)

    priority = [0] * n
    depth = [0] * n

    # get all heights and nodes in each level
    max_depth = get_height(depth)

    # count the paths that passes from each node
    paths(max_depth, depth, priority)
    # set the priority by weighting with the height
    for node in range(n):
        priority[node] -= depth[node]

    priority.sort()
    return sum(priority[k:])


if __name__ == "__main__":
    if debug:
        print("-" * 20)
    if debug:
        print("ANS: ", end="")

    ans = solve()
    print(ans)
