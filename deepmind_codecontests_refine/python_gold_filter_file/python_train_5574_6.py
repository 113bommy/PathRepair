n, m = list(map(int, input().split()))

A, B = 1, n

for _ in range(m):
    u, v = list(map(int, input().split()))
    if u > v:
        u, v = v, u
    A = max(A, u)
    B = min(B, v)

print(max(B-A, 0))