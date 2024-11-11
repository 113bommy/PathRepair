#ライブラリインポート
from collections import defaultdict
con = 998244353
INF = float("inf")

def getlist():
	return list(map(int, input().split()))

N, A, B, K = getlist()

fac = [0] * (N + 1)
inv = [0] * (N + 1)
finv = [0] * (N + 1)
fac[0], fac[1] = 1, 1
inv[1] = 1
finv[0], finv[1] = 1, 1

# 前計算
for i in range(2, N + 1):
	fac[i] = fac[i - 1] * i % con
	inv[i] = inv[con % i] * (con - (con // i)) % con
	finv[i] = finv[i - 1] * inv[i] % con

#処理内容
def main():
	ans = 0
	for i in range(N + 1):
		if (K - i * A) % B == 0:
			j = int((K - i * A) // B)
			if 0 <= j and j <= N:
				ans += (fac[N] * finv[i] * finv[N - i] * fac[N] * finv[j] * finv[N - j]) % con
				ans %= con

	#出力
	print(ans)

if __name__ == '__main__':
	main()