import math
t = int(input())
for _ in range(t):
    n = int(input())
    m = math.ceil(math.log2(n+1)) - 1
    print(m)
    if m == 1:
        print(n - 2)
    else:
        a = []
        for i in range(m+1):
            if i <= m-2:
                a.append(2 ** i)
            elif i == m-1:
                a.append(min(math.ceil((n - 2 ** (m-1) + 1)/3),2 ** (m-2)))
            else:
                a.append(n - 2 ** (m-1) + 1 - a[m-1])
        res = []
        for i in range(1,m+1):
            res.append(a[i] - a[i-1])
        print(' '.join(map(str,res)))