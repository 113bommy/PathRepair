n, m = map(int, input().split())
streets = [list(map(int, input().split())) for _ in range(n)]
print(min(map(lambda x: max(x), streets)))
