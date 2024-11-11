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
n = II()
a = sorted(LI())
ans = 0
for i in range(n):
	for j in range(i+1,n):
		for k in range(j+1,n):
			ans = max(ans,ans|a[i]|a[j])
print(ans)


