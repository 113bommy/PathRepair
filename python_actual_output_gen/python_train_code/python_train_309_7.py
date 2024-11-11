n, m, z = map(int, input().split())
print(len(set(range(n, z, n)).intersection(set(range(m, z, m)))))