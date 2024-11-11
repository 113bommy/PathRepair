n=input()
d=int(input())
m=len(n)
mod=10**9+7

DP=[[[0]*d for _ in range(2)] for _ in range(m+1)]
DP[0][0][0]=1

for i in range(1,m+1):
    for flag in range(2):
        num=9 if flag else int(n[i-1])
        for j in range(d):
            for k in range(num+1):
                DP[i][flag or k<num][(j+k)%d] +=DP[i-1][flag][j]
                DP[i][flag or k<num][(j+k)%d] %=mod

print((DP[-1][0][0]+DP[-1][1][0]-1)%mod)