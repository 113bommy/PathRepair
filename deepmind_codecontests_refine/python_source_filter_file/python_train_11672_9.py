N, M, K, L = map(int, input().split())
t = ((K + L) // M) + 1
if t * M <= N:
    print(t)
else:
    print(-1)
