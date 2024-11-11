import math
from collections import defaultdict

t = int(input())
for _ in range(t):
    n = int(input())
    tot = n // 4
    rem = n % 4
    ans = "9"*(n-tot-1)
    if rem == 0:
        ans += "9"
    else:
        ans += "8"
    ans += ("0"*tot)
    print(ans)
