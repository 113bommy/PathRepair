N, K = map(int, input().split())
h = sorted([int(input()) for i in range(N)])
print(min([h[i+K] - h[i] for i in range(N-K+1)]))