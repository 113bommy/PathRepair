from math import gcd
from functools import reduce

def find_gcd(lis):
    x = reduce(gcd, lis)
    return x


def answer(n, lis):
    sum_val = sum(lis)
    x = max(lis)

    new_lis = []

    while (1):
      for item in lis:
        new_lis.append(x - item)
      
      z = find_gcd(new_lis)
      y = sum(new_lis) / z
      break

    return y, z


n = int(input())
lis = list(map(int,input().split()))

y,z = answer(n,lis)

print(y,z)
