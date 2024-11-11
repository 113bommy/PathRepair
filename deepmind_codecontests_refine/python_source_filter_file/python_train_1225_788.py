n, k = map(int, input().split())
a = list(map(int, input().split()))
sorted(a)
print(sum(a[:k]))