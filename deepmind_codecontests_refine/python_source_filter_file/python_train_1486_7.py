# import sys; input = sys.stdin.buffer.readline
# sys.setrecursionlimit(10**7)
from collections import defaultdict
con = 10 ** 9 + 7; INF = float("inf")

def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	N, M = getlist()
	if N >= 4 and M >= 4:
		print(-1)
		return

	if N == 1 or M == 1:
		print(0)
		return

	S = []
	for i in range(N):
		s = list(map(int, list(input())))
		S.append(s)

	if N == 2:
		L = [0] * M
		for i in range(M):
			L[i] = (S[0][i] + S[1][i]) % 2

		ans = INF
		val = 0
		for i in range(M):
			if i % 2 == 0:
				if L[i] % 2 == 0:
					val += 1
			else:
				if L[i] % 2 == 1:
					val += 1

		ans = min(ans, val)

		val = 0
		for i in range(M):
			if i % 2 == 0:
				if L[i] % 2 == 1:
					val += 1
			else:
				if L[i] % 2 == 0:
					val += 1

		ans = min(ans, val)
		print(ans)
		return

	# N == 3
	else:
		DP = [[INF] * 8 for i in range(M)]
		# print(S)
		for i in range(2):
			for j in range(2):
				for k in range(2):
					DP[0][4 * i + 2 * j + k] = (S[0][0] ^ i) + (S[1][0] ^ j) + (S[2][0] ^ k)

		for x in range(1, M):
			for i in range(2):
				for j in range(2):
					for k in range(2):
						itr = 4 * i + 2 * j + k
						if itr == 0:
							DP[x][itr] = min(DP[x - 1][2], DP[x - 1][5]) + (S[0][x] ^ 0) + (S[1][x] ^ 0) + (S[2][x] ^ 0)
						elif itr == 1:
							DP[x][itr] = min(DP[x - 1][3], DP[x - 1][4]) + (S[0][x] ^ 0) + (S[1][x] ^ 0) + (S[2][x] ^ 1)
						elif itr == 2:
							DP[x][itr] = min(DP[x - 1][0], DP[x - 1][7]) + (S[0][x] ^ 0) + (S[1][x] ^ 1) + (S[2][x] ^ 0)
						elif itr == 3:
							DP[x][itr] = min(DP[x - 1][1], DP[x - 1][6]) + (S[0][x] ^ 0) + (S[1][x] ^ 1) + (S[2][x] ^ 1)
						elif itr == 4:
							DP[x][itr] = min(DP[x - 1][1], DP[x - 1][6]) + (S[0][x] ^ 1) + (S[1][x] ^ 0) + (S[2][x] ^ 0)
						elif itr == 5:
							DP[x][itr] = min(DP[x - 1][0], DP[x - 1][7]) + (S[0][x] ^ 1) + (S[1][x] ^ 0) + (S[2][x] ^ 1)
						elif itr == 6:
							DP[x][itr] = min(DP[x - 1][4], DP[x - 1][3]) + (S[0][x] ^ 1) + (S[1][x] ^ 1) + (S[2][x] ^ 0)
						elif itr == 7:
							DP[x][itr] = min(DP[x - 1][5], DP[x - 1][2]) + (S[0][x] ^ 1) + (S[1][x] ^ 1) + (S[2][x] ^ 0)

		# print(DP)
		ans = min(DP[-1])
		print(ans)





if __name__ == '__main__':
	main()