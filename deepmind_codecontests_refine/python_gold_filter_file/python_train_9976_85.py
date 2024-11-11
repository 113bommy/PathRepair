x = int(input())
set_x = set(n**e for n in range(32) for e in range(2, 11) if n**e <= x)
ans = max(set_x)
print(ans)