k, n, s, p = [int(i) for i in input().split()]
if(n % s == 0):
    a = n/s
else:
    a = n//s + 1
if (k*a % p == 0):
    print(k*a // p)
else:
    print(k*a//p + 1)