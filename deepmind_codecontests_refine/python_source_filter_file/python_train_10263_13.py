n, *a = int(input()), map(int, input().split())
print(max(n - a.count(min(a)) - a.count(max(a)), 0))
