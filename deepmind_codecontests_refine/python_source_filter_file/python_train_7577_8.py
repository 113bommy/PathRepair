N = int(input())
S = list(input())
MOD = 10**9+7
BW = "BW"
ans = 1
hoge = 0
for i in range(2*N):
    if S[i] == BW[i%2]:
        hoge += 1
    else:
        ans *= hoge
        ans %= MOD
        hoge -= 1
if S[-1] == "W":
    ans = 0
for i in range(1,N+1):
    ans *= i
    ans %= MOD
print(ans)