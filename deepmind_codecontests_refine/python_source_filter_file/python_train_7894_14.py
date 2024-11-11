from math import factorial

N,M = map(int,input().split())

def foo(N,M):
	if N == M+1 or N+1 == M:
		tm = factorial(min(N,M))
		return(tm*max(N,M)+tm)

	elif N==M:
		return(2*factorial(N)*2)

	else:
		return(0)

print(foo(N,M)/(10**9+7))