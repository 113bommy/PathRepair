n = int(input())

ans = 0
surplus = 0
for i in range(n):
    a = int(input())
    if a == 0:
        surplus = 0
        continue
    a += surplus

    ans += a // 2
    surplus %= 2

print(ans)
