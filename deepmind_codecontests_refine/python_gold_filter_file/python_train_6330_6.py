MOD = 998244353
def pow(n,k,m):#n^k mod m
    ans = 1
    while k>0:
        if(k & 1):ans = (ans*n) % m
        n = (n*n)%m
        k >>= 1
    return ans

n = int(input())
a =[int(input()) for i in range(n)]
s = sum(a)
dp1 = [0 for i in range(s+1)] #dp1[x]:Bの和=xとなるような塗り方の総数

dp1[0] = 1

for i in  a:
    dpp1 = [0 for i in range(s+1)]
    for j in range(s+1):
        if j+i <= s:dpp1[j+i] = (dp1[j]+dpp1[j+i]) % MOD
        dpp1[j] = (dp1[j]*2 + dpp1[j]) % MOD
    dp1 = dpp1[:]

if s % 2 == 1:
    ans1 = sum(dp1[(s//2) + 1:]) % MOD
    print((pow(3,n,MOD)-ans1*3) % MOD)
    exit()

ans1 = sum(dp1[(s//2):]) % MOD

dp2 = [0 for i in range(s+1)]

dp2[0] = 1

for i in a:
    dpp2 = [0 for i in range(s+1)]
    for j in range(s+1):
        if j+i <= s:dpp2[j+i] = (dp2[j]+dpp2[j+i]) % MOD
        dpp2[j] = (dp2[j] + dpp2[j]) % MOD
    dp2 = dpp2[:]

print((pow(3,n,MOD)-(ans1*3 - dp2[s//2]*3)) % MOD)