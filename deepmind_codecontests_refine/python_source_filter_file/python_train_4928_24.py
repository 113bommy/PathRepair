(n, a, b) = list(map(int, input().split()))
h = list(map(int, input().split()))

h.sort()

d1 = h[a]
d2 = h[b]

print(d2 - d1)