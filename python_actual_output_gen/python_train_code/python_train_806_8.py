a, b, c, d = map(int, input().split())
x = list(sorted([a, b, c]))
print(sum([x[i + 1] - x[i] - d for i in range(2) if x[i + 1] - x[i] < d]))
