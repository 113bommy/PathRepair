def arr_inp():
    return [int(x) for x in input().split()]


from math import *

a = arr_inp()
v1 = a[2] / ((pow(.5 * a[0], 2) * pi))
if (a[3] >= v1):
    print('NO')
else:
    print('YES')
    print('{:.12f}'.format(a[1]/(v1-a[3])))
