import sys
import bisect
try:
	fin = open('in')
except:
	fin = sys.stdin
input = lambda: fin.readline().strip()

s = input()
r = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_'
t = sum(bin(r.index(u)).count('1') for u in s)
ans = 1
mod = 10 ** 9 + 7
a = 3
while t:
	if t & 1: ans = ans * a % mod
	a = a * a % mod
	t >>= 1
print (ans)