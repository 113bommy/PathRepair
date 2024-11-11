import sys; input = sys.stdin.buffer.readline
from collections import defaultdict
con = 10 ** 9 + 7; INF = float("inf")

def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	N = int(input())
	S = getlist()
	ans = 0
	for i in range(1, N):
		if (N - 1) % i == 0:
			var = 0
			left = 0; right = 0
			cnt = 0
			while True:
				if 2 * i * cnt >= N - 1:
					break
				left += S[i * cnt]
				right += S[N - 1 - i * cnt]
				var = max(var, left + right)
				cnt += 1

			ans = max(ans, var)
			
		else:
			var = 0
			left = 0; right = 0
			cnt = 0
			while True:
				if i * cnt > N - 1:
					break
				left += S[i * cnt]
				right += S[N - 1 - i * cnt]
				var = max(var, left + right)
				cnt += 1

			ans = max(ans, var)

	print(ans)

if __name__ == '__main__':
	main()