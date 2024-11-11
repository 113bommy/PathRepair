w, h, k = map(int, input().split())

ans = 0
for i in range(k):
    if w == 1:
        ans += h
    elif h == 1:
        ans += w
    else:
        ans += w * 2 + h * 2 - 4
    w -= 2
    h -= 2
print(ans)
