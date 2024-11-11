from math import sqrt

inp = input()

l = list(map(int, inp.split(' ')))
A = l[0]
B = l[1]
n = l[2]

for i in range(n):
    inp = input()
    temp = list(map(int, inp.split(' ')))
    l = temp[0]
    t = temp[1]
    m = temp[2]

    imp = 0
    a = B/2
    b = (A - 1/2 * B)
    c = -A * (l - 1) + B*l/2 - B*l*l/2 + B - t*m

    res1 = 0

    if b*b - 4 * a * c > 0:
        res1 = int((-b + sqrt(b*b - 4 * a*c) )/ (2 *a))
    else:
        imp = 1

    res2 = 0

    if (t - A - B*(-1))/B > 0:
        res2 = int((t - A - B*(-1))/B)
    else:
        imp = 1
    if res2 < l:
        imp = 1

    if not imp:
        print(min(res1, res2))
    else:
        print(-1)
