n, k = map(int, input().split())
print(sum(1 for i in map(int, input().split()) if i >= k))