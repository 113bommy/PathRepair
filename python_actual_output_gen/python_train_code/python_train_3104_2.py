n, k = map(int, input().split())
print(sum(sorted((list(map(int, input().split())))[:0 if n<k else n-k])))