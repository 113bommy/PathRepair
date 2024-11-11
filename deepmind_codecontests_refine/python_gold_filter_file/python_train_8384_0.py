n, L, v1, v2, k = map(int, input().split())
dif = v2 - v1
n = (n + k - 1) // k * 2
p1 = (n * v2 - dif) * L
p2 = (n * v1 + dif) * v2
print(p1 / p2)