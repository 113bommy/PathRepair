import sys
from sys import stdin, stdout


def possible(a, b, c, d):
    if b >= a-1 and c >= d-1 and (b - a == c - d or b - a + 1 == c - d or b - a == c - d + 1):
        return True
    else:
        return False


if __name__ == '__main__':

    A = stdin.readline().strip().split()
    a = int(A[0])
    b = int(A[1])
    c = int(A[2])
    d = int(A[3])

    if not possible(a, b, c, d):
        print('NO')
        sys.exit()

    res = []
    rng = a + b + c + d
    pre = -1
    for i in range(a + b + c + d):
        if (pre == 1 or pre ==-1) and a > 0 and possible(a-1, b, c, d):
            a -= 1
            res.append(0)
            pre = 0
        elif (pre == 0 or pre == 2 or pre == -1) and b > 0 and possible(a,b-1,c,d):
            b -= 1
            res.append(1)
            pre = 1
        elif (pre == 1 or pre == 3 or pre == -1) and c > 0 and possible(a, b, c-1, d):
            c -= 1
            res.append(2)
            pre = 2
        elif (pre == 2 or pre == -1) and d > 0 and possible(a, b, c, d-1):
            d -= 1
            res.append(3)
            pre = 3
        #else:
        #    print('NO')
        #    sys.exit()

    print('YES')
    print(" ".join(map(str, res)))