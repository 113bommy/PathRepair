n = int(input())
ans = 0
for i in range(9):
    level = 10 ** i * 9
    ans += min(n, level) * (i + 1)
    n -= level
    if n < 1:
        break
print(ans)
