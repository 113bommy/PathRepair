# import sys; input = sys.stdin.buffer.readline
# sys.setrecursionlimit(10**7)
from collections import defaultdict
mod = 10 ** 9 + 7; INF = float("inf")

def getlist():
	return list(map(int, input().split()))

def main():
	T = int(input())
	for _ in range(T):
		N = int(input())
		A = getlist()
		S = sum(A)
		if S == 0:
			print("NO")
		elif S < 0:
			A.sort()
			print("YES")
			print(*A)
		else:
			print(A.sort(reverse=True))
			print("YES")
			print(*A)




if __name__ == '__main__':
	main()