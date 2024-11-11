N, K, *H = map(int, open(0).read().split())
H.sort()
a = float('inf')
for i in range(N-K+1):
    a = min(a, H[i+K-1]-H[i])
print(a)