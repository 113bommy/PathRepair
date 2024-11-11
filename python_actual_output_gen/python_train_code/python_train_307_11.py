import time

n = int(input())
a = int(input())
b = int(input())
c = int(input())

_b = int(b);
b -= c

second = 0
if(n >= _b) :
    second = (n - _b) // b + max(1 + (((n - _b) % b) // a), ((n - _b) % b + _b) // a)

print(max(n // a, second))