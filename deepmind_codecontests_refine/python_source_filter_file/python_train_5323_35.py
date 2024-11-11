import math
n = int(input())
l = math.ceil(n/7)
a, b = 0, 0
A, B = -1, -1
mini = 1000005
while b <= l:
    a = (n-(7*b))/4
    if a > 0 and int(a) == a:
        a = int(a)
        if (a+b) < mini:
            mini = a+b
            A, B = a, b
        elif (a+b) == mini:
            if b < B:
                A, B = a, b
    b += 1
if (4*A + 7*B) == n:
    print('4'*A + '7'*B)
else:
    print(-1)