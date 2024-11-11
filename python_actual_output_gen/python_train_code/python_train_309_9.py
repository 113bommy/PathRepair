n, m, z = map(int, input().split())
print(len(set(range(1, z+1, n)).intersection(set(range(1, z+1, m)))))