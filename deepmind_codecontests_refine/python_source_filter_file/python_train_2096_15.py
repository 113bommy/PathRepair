import math
T = int(input())
for i in range(T):
    n = int(input())
    x = math.gcd(180,n)
    n = n//x
    a = 180//x
    if n == a-1:
        print(2*n)
    else:
        print(n)