import math

n = int(input())

for _ in range(n):
    a = int(input())
    b = int(a)
    sqr = int(math.log(b, 2)) + 1
    print(int((a*(a+1)) / 2 - ((2**sqr)-1)*2))
