S = input()
N = len(S)
DP =[0]*13
DP[0] = 1
A = 0
MOD = 10**9+7

T = [1,10,9,12,3,4]
A = 0
for i in range(N):
    A*=10
    if S[i] == "?":
        hoge = [0]*13
        for j in range(13):
            for k in range(10):
                hoge[(j+k*T[(N-i-1)%6])%13] = (hoge[(j+k*T[(N-i-1)%6])%13] + DP[j])%MOD
        DP = hoge[:]
    else:
        A += int(S[i])
    A = A%13
print(DP[(A+5)%13])