N, K = [int(x) for x in input().split()]
h = [int(input()) for x in range(N)]
h.sort()
print(min([h[i+K-1] - h[i] for i in range(N-K+1)]))
