n, m = map(int, input().split())

ans = 0
s = n

while True:
    s -= 1
    if (ans - 1) % m == 0:
        s += 1
    if s == 0:
        break
    ans += 1

print(ans)