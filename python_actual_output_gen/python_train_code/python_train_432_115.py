n, k = map(int, input().split())
a = list(map(int, input().split())).sort()
print(sum(a[:k]))