import math
a = [int(x) for x in input().split()]
b = [int(y) for y in input().split()]
n = int(input())
c = math.ceil(sum(a)/10)
d = math.ceil(sum(b)/10)
if c+d<=n:
    print('YES')
else:
    print('NO')