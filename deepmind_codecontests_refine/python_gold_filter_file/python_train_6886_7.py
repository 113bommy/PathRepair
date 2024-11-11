k=int(input())
a = int(input())

import math

u=round(math.log(a,k),15)


if int(u)==u:
    print('YES')
    print(int(u-1))
else:
    print('NO')
