x = int(input())
a, b  = list(map(int, input().split()))
ans = 0
while (a % 10 != 7) and (b % 10 != 7):
    b = b - x
    if b < 0:
        b = -b + 24
        a = a - 1
    if a < 0:
        a = 24
    ans += 1

print(ans)