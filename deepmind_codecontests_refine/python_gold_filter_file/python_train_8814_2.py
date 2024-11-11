from sys import stdin, stdout
from math import gcd
input = stdin.buffer.readline

x, k = map(int, input().split())
if x == 0:
	print(0)
	exit()
x *= 2
mod = 1000000007
x = pow(2, k, mod) * x % mod - (pow(2, k, mod) - 1)
print(x % mod)
