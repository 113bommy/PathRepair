_, K = map(int, input().split())
h = list(map(int, input().split()))
print(sum([c >= K for c in h]))