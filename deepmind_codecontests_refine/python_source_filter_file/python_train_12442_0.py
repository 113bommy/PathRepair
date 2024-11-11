n, m = map(int, input().split())
result = 0
for pos in range(1, n):
    row = list(map(int, input().split()))
    result = max(result, min(row))
print(result)
