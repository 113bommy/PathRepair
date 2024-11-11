#1277B
from math import floor
t = int(input())
for tries in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    if n == 1:
        k = 0
        while a[0] %2**(k+1) == 0:
            k += 1
        print(k)
    else:
        b = []
        for i in range(n):
            k = 0
            while a[i] %2**(k+1) == 0:
                k += 1
            a[i]= a[i]//(2**k)
            b.append(k)
        a, b = (list(t) for t in zip(*sorted(zip(a, b))))
        s = 0
        i = 0
        while i < n-1:
            if not a[i] == a[i+1]:
                s += b[i]
                if n > 1 and i == n-2:
                    s += b[n-1]
            elif i == n-2:
                s += b[n-1]
            i += 1
    print(s)