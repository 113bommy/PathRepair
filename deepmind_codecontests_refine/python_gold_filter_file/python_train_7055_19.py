'''
完全順列(derangement)
モンモール数(Montmort number)
'''

MOD = 10**9+7
N, M = map(int, input().split())

# 片方の順列の総数を求める
ans = 1
for i in range(N):
    ans *= M-i
    ans %= MOD

# M枚からN枚選ぶ完全順列を計算
d2, d1 = 1, M-N
d0 = d1
for i in range(2, N+1):
    # 1がk番目にある
    # 1番目にkがある
    d0 = (i-1)*d2 % MOD
    # 1番目にkがない
    d0 += (M-N+i-1)*d1
    d0 %= MOD
    d2, d1 = d1, d0

print(ans*d0 % MOD)
