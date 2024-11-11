n, m, z = map(int, input().split())
print(len(set(range(n, z+1, n)).intersection(set(range(m, z+1, m)))))