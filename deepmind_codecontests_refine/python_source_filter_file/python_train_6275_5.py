from math import sqrt

t = int(input())
for _ in range(t):
    n = int(input())
    if n < 2:
        print(0)
    else:
        a = b = int(sqrt(n))-1
        temp = 1
        while((a+1)*b<n or a*(b+1)<n):
            a += temp
            b += (1-temp)
            temp = 1 - temp
        print(a+b-1)