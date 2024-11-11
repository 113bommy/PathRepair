a, b, c, k = map(int, input().split())
ans = a - max(0, k - a - b)
print(ans)