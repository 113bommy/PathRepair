a, b, c, d =map(int,input().split())
ans = max(min(b, d) - max(a, c), 0)
print(ans)