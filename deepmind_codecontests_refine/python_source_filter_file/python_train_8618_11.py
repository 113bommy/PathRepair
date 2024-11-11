N, K = map(int, input().split())
h = list(map(int, input().split()))
print(sum(1 if t >= K for t in h))