from math import gcd
from functools import reduce

n = int(input())
a = [int(i) for i in input().split()]

kek = reduce(gcd, a)
i = 1
mem = []

if kek == 1:
    print(1)
    quit()


while i**2 <= kek:
    if kek % i == 0:
        mem.append(i)
        mem.append(kek // i)
    i += 1

print(len(mem))
