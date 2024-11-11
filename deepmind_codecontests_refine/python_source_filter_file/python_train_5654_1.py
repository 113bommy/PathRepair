import sys
n, a, b = input().split()
n = int(n)
a = int(a)
b = int(b)
if b == 0 and a > 0:
    if a == n-1:
        print(-1)
        sys.exit()
    print(1, end = " ")
    n-=1
for i in range(b+1) :
    print(2**i, end = " ")
for i in range(a) :
    print(2**b + i, end = " ")
for i in range(n - a- b-1) :
    print(1, end = " ")
