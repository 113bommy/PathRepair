N, K = map(int, input().split())
h = sorted([int(input()) for _ in range(N)])
print(min([h[i+K-1]-h[i] for i in range(N - K + 1)]))