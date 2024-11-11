#!/usr/bin/env python3
import math

a, b = map(int,input().split())
diff = a - b
if diff < 0:
    print(0)
elif diff == 0:
    print("infinity")
else:
    cnt = 0
    for i in range(1, int(math.sqrt(diff))):
        if diff % i == 0 and i > b:
            cnt += 1
        if diff %i == 0 and diff // i > b and i * i != diff:
            cnt += 1
    print(cnt)
