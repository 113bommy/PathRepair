N,K,*h=map(int,open(0).read().split())
h.sort()
_min = 10**9
for i in range(N+1-K):
    _min = min(_min, h[i+K-1] - h[i])
print(_min)