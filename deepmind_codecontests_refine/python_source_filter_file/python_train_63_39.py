n, k = (int(x) for x in input().split())
a = [int(x) for x in input().split()]
import math
p = int(math.sqrt(k) + 1)
b = []
for i in range(1, p):
    if k % i == 0:
        b.append(i)
        b.append(k/i)
b.append(k)
b.sort(reverse=True)
for i in b:
    if i in a:
        print(k / i)
        exit()