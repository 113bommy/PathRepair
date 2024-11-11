n, m = map(int, input().split())

ans = max(n, m // 2)
ans += (m - ans * 2) // 4
print(ans)
