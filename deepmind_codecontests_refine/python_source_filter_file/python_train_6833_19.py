import math

def calc(a):
    i = 0
    while(1<<i < a):
        i += 1;
    return i

A,B = input().split()
a = int(A)
b = int(B)

if(b == 1):
    print(a)
else:
    print((1 << calc(a)) - 1)

