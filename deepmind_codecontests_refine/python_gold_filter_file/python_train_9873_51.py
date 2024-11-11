n, a, b = map(int, input().split())
print(sum(x for x in range(1, n+1) if a <= sum(map(int, str(x))) <= b))
