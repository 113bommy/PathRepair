N = int(input())
mod = 998244353
# DP ナップサックぽいやつ
# DP[i][j] := a_0からa_iまでの部分集合で和がjになるものの個数
# 配るDPの方が場合分けがなくて簡潔に書ける 計算量増えるかも
# DP[i-1][j]→DP[i][j]とDP[i][j + a_i ]に配る

aaa = [int(input()) for _ in range(N)]

sum_now = 0
DP = [[0] * (sum(aaa)+1) for i in range(N)]
DP2 = [[0] * (sum(aaa)+1) for i in range(N)]

a = aaa[0]
DP[0][0] = 2
DP[0][a] = 1

DP2[0][0] = 1
DP2[0][a] = 1

sum_now += a

for i in range(1, N):
	a = aaa[i]
	for j in range(sum(aaa)):
		DP[i][j] += DP[i-1][j] * 2
		DP[i][j] %= mod
		DP[i][j + a] += DP[i-1][j]

		DP2[i][j] += DP2[i-1][j]
		DP2[i][j] %= mod
		DP2[i][j + a] += DP2[i-1][j]

	sum_now += a

# print(DP2)
minimum_invalid_length = int((sum_now+1)//2)
num_too_long = sum (DP[N-1][minimum_invalid_length:])
if (sum(aaa) %2 == 0):
	num_too_long -= DP2[N-1][int(sum(aaa) /2)]
# print(num_too_long)
# print(sum(aaa))
print((3** N - num_too_long * 3) % mod )
