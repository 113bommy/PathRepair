import sys
import collections

input = sys.stdin.readline

def printnl(val):
	sys.stdout.write(str(val) + '\n')


n, m = map(int, input().split())

cur = 1
while m:
	if m >=  cur:
		m -= cur
	else:
		break
	cur += 1
	if cur == n + 1:
		cur = 1
	printnl(m)