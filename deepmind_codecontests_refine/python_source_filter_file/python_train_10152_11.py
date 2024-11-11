import math
l, r, k = [int(x) for x in input().split()]
exists = False
for x in range(1, int(math.log(10**18)/math.log(k))+1):
    value = k**x
    if l <= value <= r:
        print(value, end=" ")
        exists = True
    if value > r:
        break

if not exists:
    print(-1)