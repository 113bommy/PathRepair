n, a, b, c, d = map(int, input().split())
s = input()
a -= 1
b -= 1
c -= 1
d -= 1

# 2個以上の岩があればNG
if "##" in s[a:max(c,d)]:
    print("No")
    exit()

# AがBを抜けるかどうか
if d < c and not "..." in s[a:c]:
    print("No")
    exit()

print("Yes")
