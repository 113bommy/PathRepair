from math import log2, floor, ceil

x, d = input().split()
x, d = int(x), int(d)

k = 1

arr = list()

c = 1
ans = True

while (x > 0):
    p = floor(log2(x))

    if (2**(p+1) - 1) <= x:
        p += 1

    if (p == 0):
        ans = False
        break

    arr.extend([k]*p)

    k += d+1

    x -= (2**p - 1)

if (ans) and (len(arr) <= 10000):
    print(len(arr))
    print(' '.join(list(map(str, arr))))
else:
    print(-1)
