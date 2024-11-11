N, K   = map(int, input().split())
x = list(map(int, input().split()))
assert len(x) == N

m = min(x[i] - x[i-K+1] + min(abs(x[i]), abs(x[i-K+1])) for i in range(K-1, N))
print(m)