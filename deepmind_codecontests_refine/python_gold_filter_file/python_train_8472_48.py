import math


n, k = map(int, input().split())
nOdd = math.ceil(n/2)

if k <= nOdd:
    print(2*k-1)
else:
    print((k-nOdd)*2)

