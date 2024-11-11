x = int(input())
ans = x // 11 * 2
x -= ans * 11
if x > 6:
    ans += 2
elif x > 0:
    ans += 1
print(ans)
