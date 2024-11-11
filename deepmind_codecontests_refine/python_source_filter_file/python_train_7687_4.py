import itertools

n, m = [int(x) for x in input().split()]
edges = set(tuple(int(x) for x in input().split()) for _ in range(m))
print(sum(1 if all(p in edges or tuple(reversed(p)) in edges for p in [(1, path[0]), *zip(path, path[1:])]) else 0 for path in itertools.permutations(range(2, n + 1))))
