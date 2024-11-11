import sys
import math
def II():
	return int(sys.stdin.readline())

def LI():
	return list(map(int, sys.stdin.readline().split()))

def MI():
	return map(int, sys.stdin.readline().split())

def SI():
	return sys.stdin.readline().strip()
n,p = MI()
a = sorted(LI())
for i in range(n):
	a[i]-=i
mi = max(a)
for i in range(n):
	a[i]+=p-1
ma = min(a[p-1:])
print(ma-mi)
print(*list(range(mi,ma)))

