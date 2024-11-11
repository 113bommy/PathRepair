# import sys; input = sys.stdin.buffer.readline
# sys.setrecursionlimit(10**7)
from collections import defaultdict
mod = 10 ** 9 + 7; INF = float("inf")
	 
def getlist():
	return list(map(int, input().split()))
	 
def inverse(N, mod):
	return (pow(N, mod - 2, mod))
	 
def main():
	T = int(input())
	for _ in range(T):
		N, K = getlist()
		A = getlist()
		D = defaultdict(int)
		for i in A:
			D[i] = 1
	 
		M = len(D)
		if K == 1 and M >= 2:
			print(-1)
			continue
		if K == 1:
			print(1)
			continue
		ans = (M - 2) // (K - 1) + 1
		print(ans)
	 
	 
if __name__ == '__main__':
	main()