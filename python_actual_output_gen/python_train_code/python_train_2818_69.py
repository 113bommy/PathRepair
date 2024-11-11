x = int(input())

ans = x // 11 * 2
if x % 11 > 6:
    ans += 2
elif x % 6 > 0:
    ans += 1

print(ans)