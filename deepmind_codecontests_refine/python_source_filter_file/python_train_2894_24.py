N, Q = map(int, input().split())

ab = []
for i in range(N-1):
    a, b = map(int, input().split())
    ab.append((a, b))
ab = sorted(ab, key=lambda x: (x[0], x[1]))

P = [0 for _ in range(N)]  # 0-indexed
for i in range(Q):
    p, x = map(int, input().split())
    P[p-1] += x

for i in range(N-1):
    a, b = ab[i]
    P[b-1] += P[a-1]

print(*P)
