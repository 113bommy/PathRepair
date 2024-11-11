import sys
readline = sys.stdin.readline

MOD = 10**9+7
def compress(L):
    L2 = list(set(L))
    L2.sort()
    C = {v : k for k, v in enumerate(L2)}
    return L2, C

N = int(readline())
height = [0]
H = list(map(int, readline().split()))
height.extend(H)

orih, C = compress(height)

L = len(orih)

dp = [0]*L
dp[0] = 1

phidx = 0
for i in range(1, N+1):
    hidx = C[H[i-1]]
    dp2 = [0]*L
    if phidx >= hidx:
        for h in range(hidx+1):
            dp2[h] = (dp[hidx]+dp[h])%MOD
    else:
        if phidx == 0:
            dp2[0] = pow(2, orih[hidx])
            for h in range(1, hidx+1):
                dp2[h] = pow(2,  orih[hidx]-orih[h]+1, MOD)
        else:
            for h in range(hidx+1):
                dp2[h] = (dp[phidx] + dp[min(phidx, h)])*pow(2, orih[hidx]-orih[max(h, phidx)])%MOD
    dp = dp2[:]
    phidx = hidx
    #print(dp)
print(dp[0])
            
