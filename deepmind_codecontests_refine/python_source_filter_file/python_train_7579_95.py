N, K = (int(x) for x in input().split())
h = [int(input()) for i in range(K)]
h.sort()
print(min(h[i+K-1] - h[i]) for i in range(N-K+1))