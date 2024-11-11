n, m = map(int, input().split())

ans = min(n, m // 2)
ans += (m - ans * 2) // 4
print(ans)
