# from debug import debug
import math

def sol(n, k):
	s = 2**n-1
	mid = s//2
	if k==mid+1:
		return n
	elif k<mid:
		return sol(n-1, k)
	else:
		k = 2*mid-k
		return sol(n-1, k)

n, k = map(int, input().split())

if k%2:
	print(1)
else:
	print(sol(n,k))