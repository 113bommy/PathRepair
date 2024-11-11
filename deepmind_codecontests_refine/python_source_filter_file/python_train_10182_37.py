import sys
sys.setrecursionlimit(10**7)
def LI(): return [int(x) for x in input().split()]
def II(): return int(input())
INTMIN = -9223372036854775808

N=II()
RA=LI()
RB=LI()
GAIN1=[]
GAIN2=[]
for i in range(3):
    if RA[i] < RB[i]:
        GAIN1.append((RA[i], RB[i]-RA[i]))
    if RA[i] > RB[i]:
        GAIN2.append((RB[i], RA[i]-RB[i]))

dp1 = [0]*(N+1)
for i in range(N+1):
    for cost, gain in GAIN1:
        if (i+cost) <= N:
            dp1[i+cost] = max(dp1[i+cost],dp1[i]+gain)

M = dp1[N]+N
dp2 = [0]*(M+1)
for i in range(N+1):
    for cost, gain in GAIN2:
        if (i+cost) <= M:
            dp2[i+cost] = max(dp2[i+cost],dp2[i]+gain)

print(M+dp2[M])