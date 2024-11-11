import math
ls = []

for i in range(11):
    ls.append(int(input()))

for i in range(11):
    var = ls.pop()
    a = math.sqrt(abs(var))
    b = (var**3)*5
    res = a + b
    if 400 >= res:
        print('f(%d) = %.2f' % (var, res))
    else:
        print('f(%d) = MAGNA NIMIS!')