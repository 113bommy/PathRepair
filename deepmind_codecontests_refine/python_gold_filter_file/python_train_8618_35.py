n, k = map(int, input().split())
print(sum(1 for h in map(int, input().split()) if h >= k))
