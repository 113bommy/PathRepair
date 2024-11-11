n, m = map(int, input().split())
edges = [map(int, input().split()) for _ in range(m)]
print(max(len({tuple(sorted((mask // (6 ** (x - 1))) % 6 for x in e)) for e in edges}) for mask in range(6 ** n)))