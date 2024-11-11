N, M = map(int, input().split())
l, r = 1, N
for _ in range(M):
    L, R = map(int, input().split())
    l = max(l, L)
    r = min(r, R)
print((max(0, r-l+1))