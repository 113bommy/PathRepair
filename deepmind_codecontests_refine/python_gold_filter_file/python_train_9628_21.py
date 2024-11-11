import math
n,k = map(int,input().split())
a = [ [0] * (n) for i in range(n) ]
if ((k > math.ceil((n * n) / 2))):
    print('NO')
else:
    print('YES')
    for i in range(n):
        if (k > 0):
            if (i % 2 == 0):
                s = 'L'
            else:
                s = 'S'
        else:
            s = 'S'
        for j in range(n):
            if (k > 0):
                a[i][j] = s
                if (s == 'S'):
                    s = 'L'
                else:
                    s = 'S'
                    k = k - 1
            else:
                s = 'S'
                a[i][j] = s
    for i in range(len(a)):
        print(''.join(a[i]))