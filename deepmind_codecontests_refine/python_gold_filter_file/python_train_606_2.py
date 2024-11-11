# 解説AC
N,M = map(int, input().split())
X = [int(i) for i in input().split()]
Y = [int(i) for i in input().split()]

MOD = 10 ** 9 + 7

def f(Z):
    ans = 0
    for k,z in enumerate(Z):
        ans = (ans + k * z - (len(Z) - k - 1) * z) % MOD
    return ans

print(f(X) * f(Y) % MOD)