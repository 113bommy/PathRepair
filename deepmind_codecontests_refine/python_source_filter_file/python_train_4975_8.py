from collections import defaultdict, Counter, deque

N, = list(map(int, input().split()))

g = defaultdict(list)
for i in range(N - 1):
    u, v = list(map(int, input().split()))
    g[u].append(v)
    g[v].append(u)

# BFS to label each node with its level (bipartite 2-coloring)
source = 1
dist = {}
q = deque()
q.append(source)
dist[source] = 0
while q:
    node = q.popleft()
    level = dist[node]
    for nbr in g[node]:
        if nbr not in dist:
            q.append(nbr)
            dist[nbr] = level + 1

mod1 = list(range(1, N + 1, 3))
mod2 = list(range(2, N + 1, 3))
mod0 = list(range(3, N + 1, 3))

# Count the number of nodes on odd and even levels
parityCounts = Counter(level % 2 for level in dist.values())

assign = {}
# Since 3 is odd, any distance of 3 will connect two nodes of different parity levels
if min(parityCounts[0], parityCounts[1]) < len(mod0):
    # Either the odd or even levels is small enough to be completely 0 mod 3 which can connect to anything else
    parityOfSmaller = min([0, 1], key=lambda k: parityCounts[k])
    for i in range(1, N + 1):
        if dist[i] % 2 == parityOfSmaller:
            assign[i] = mod0.pop()
        else:
            if mod0:
                assign[i] = mod0.pop()
            elif mod1:
                assign[i] = mod1.pop()
            elif mod2:
                assign[i] = mod2.pop()
else:
    # We want to assign all (1 mod 3) to one parity and all (2 mod 3) to another parity
    # Then the sum will always be a multiple of 3
    # The two levels should always have enough nodes to consume all of mod1 and mod2
    # Anything else can be padded with mod0
    assert len(mod0) <= len(mod2) <= len(mod1)

    if parityCounts[0] < parityCounts[1]:
        assert len(mod2) <= parityCounts[0]
        assert len(mod1) <= parityCounts[1]
        parityToMod = {0: mod2, 1: mod1}
    else:
        assert len(mod1) <= parityCounts[0]
        assert len(mod2) <= parityCounts[1]
        parityToMod = {0: mod1, 1: mod2}

    for i in range(1, N + 1):
        mod = parityToMod[dist[i] % 2]
        if mod:
            assign[i] = mod.pop()
        else:
            assign[i] = mod0.pop()

print(" ".join(str(assign[i]) for i in range(1, N + 1)))
