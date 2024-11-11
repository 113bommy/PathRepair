n, k = map(int, input().split())
p = list(map(int, input().split()))
p = p.sort()
print(sum(p[:k]))