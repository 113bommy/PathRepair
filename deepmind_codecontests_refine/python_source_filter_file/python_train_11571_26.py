n, v = map(int, input().split())

ans = 0
i = 1
w = 0

while True:
    dw = min(v, n - i - w)

    if dw <= 0:
        break

    w += dw
    ans += i * dw

    i += 1
    w -= 1

print(ans)
