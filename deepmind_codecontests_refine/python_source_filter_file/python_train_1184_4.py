N, K = map(int, input().split())

def in_bounds(k):
    return N <= K*(K+1)/2 - (K-k)*(K-k+1)/2 - k + 1

l = 1
r = K
while l <= r:
    c = (l + r) // 2
    if in_bounds(c):
        r = c - 1
    else:
        l = c + 1
if in_bounds(K):
    print(l)
else:
    print(-1)
