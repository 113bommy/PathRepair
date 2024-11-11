n, m = (int(_) for _ in input().split())
ans = min(n, m // 2)
m -= ans * 2
ans += m // 3
print(ans)
