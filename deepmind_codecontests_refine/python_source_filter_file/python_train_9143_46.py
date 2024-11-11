a, b, c, d = map(int, input().split())
ans = max(0, max(a, c) - min(b, d))
print(ans)
