N, K = map(int, input().split())
h = list(map(int, input().split()))

print(sum([t >= K for t in h]))