import sys

def main():
	n = int(sys.stdin.readline())
	x = list(map(int, sys.stdin.readline().split()))
	MOD = int(1e5 + 1)
	print(n + 1)
	add = 0
	for i in range(n - 1, -1, -1):
		x[i] += add
		#~ print(add)
		if x[i] % MOD == i:
			print(1, i + 1, 0)
		elif x[i] % MOD < i:
			print(1, i + 1, i - (x[i] % MOD))
			add += i - (x[i] % MOD)
		else:
			q = i + MOD - (x[i] % MOD) - 1
			print(1, i + 1, q)
			add += q
	print(2, n, MOD)
	
	
main()
