from sys import stdin,stdout
from math import gcd, ceil, sqrt
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

a, b, c = iia()
one = (-b + sqrt(b ** 2 - (4 * a * c))) / 2 * a
two = (-b - sqrt(b ** 2 - (4 * a * c))) / 2 * a
if one > two:
    print(one, two, sep="\n")
else:
    print(two, one, sep="\n")
    