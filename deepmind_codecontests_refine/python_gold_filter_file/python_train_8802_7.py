import sys, math, random
a, b, c = map(int, input().split())
ans = 10 ** 100
#всего поровну
max_ = max(a, b, c)
ans = max_ - a + max_ - b + max_ - c
#больше на 1 завтрак
if a > b and a > c:
    ans = min(ans, a - 1 - b + a - 1 - c)
else:
    ans = min(ans, max_ + 1 - a + max_ - b + max_ - c)
#больше на 1 завтрак и на 1 обед
gg = max(a, b)
hh = max(a, c)
tt = max(b, c)
if gg > c:
    ans = min(ans, gg - a + gg - b + gg - c - 1)
else:
    ans = min(ans, c + 1 - a + c + 1 - b)
#больше на 1 обед
if b > a and b > c:
    ans = min(ans, b - 1 - a + b - 1 - c)
else:
    ans = min(ans, hh - a + hh - c + hh + 1 - b)
#больше на 1 обед и на 1 ужин
if tt > a:
    ans = min(ans, tt - a - 1 + tt - b + tt - c)
else:
    ans = min(ans, a + 1 - b + a + 1 - c)
#больше на 1 ужин
if c > a and c > b:
    ans = min(ans, c - a - 1 + c - b - 1)
else:
    ans = min(ans, gg - a + gg - b + gg + 1 - c)
#больше на 1 ужин и на 1 затврак
if hh > b:
    ans = min(ans, hh - a + hh - b - 1 + hh - c)
else:
    ans = min(ans, b + 1 - a + b + 1 - c)
print(ans)

    
