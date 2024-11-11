a1, a2 = map(int, input().split())
b, c, ans = min(a1, a2), max(a1, a2), 0 # b < c
while c-b > 1:
    c -= 2
    b += 1
    ans += 1
b, c = min(b, c), max(b, c)
print(1 if b < 2 and c < 2 else ans + (c-2)*2 + 1)