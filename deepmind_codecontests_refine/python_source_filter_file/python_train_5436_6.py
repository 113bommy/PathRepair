from math import factorial as fact

mod = 10**9 + 7

def C(n, k):
	return fact(n) // (fact(n-k) * fact(k))
	
n, m = map(int, input().split())
print(C(n + 2*m - 1, 2*m))
