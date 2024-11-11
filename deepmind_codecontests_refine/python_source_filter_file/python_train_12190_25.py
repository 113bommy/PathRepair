from sys import stdin
from math import *
from decimal import *

line = stdin.readline().rstrip().split()
n = int(line[0])
m = int(line[1])
bigNum = (n-1)*n/2
smallN = int(floor((n-1)/2))
bigN = (n-1) - smallN
smallNum = smallN*(smallN+1)/2
smallNum2 = bigN*(bigN+1)/2
total = Decimal(0)
getcontext().prec = 7
for i in range(m):
    line = stdin.readline().rstrip().split()
    x = int(line[0])
    d = int(line[1])
    total += Decimal(x*n)
    if d < 0:
        total += Decimal(smallNum*d) + Decimal(smallNum2*d)
    else:
        total += Decimal(bigNum*d)
print(Decimal(total)/Decimal(n))
