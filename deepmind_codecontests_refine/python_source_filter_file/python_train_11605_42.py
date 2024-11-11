import sys
import math
a, m = map(int, input().split())

if a % m == 0 or 2*a % m == 0:
    print("Yes")
    sys.exit()

a1 = a
f = False
for k in range(int(math.log(m))):
    if a * (2 ** k) % m == 0:
        f = True
        break

if f:
    print("Yes")
else:
    print("No")
