n = int(input())
ans = 0
while n > 0:
    n -= max(map(int, str(n)))
    ans += 1
print(ans)
