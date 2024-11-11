import math
import sys

a = sys.stdin.readline().split(' ')
n = int(a[0])
m = int(a[1])

modulator = 1000000007

if n == m:
	print((math.factorial(n) * math.factorial(m) * 2) % modulator)
elif abs(n - m) == 1 :
	print((math.factorial(n) * math.factorial(m)) % modulator)
else:
	print(0)
