#http://compro.tsutajiro.com/archive/180220_probability_dp.pdf
import sys
n = int(input())
a = list(map(int, sys.stdin.readline().split( )))
cnt =[0,0,0]
for i in range(n):
    cnt[3-a[i]] += 1
dp = [[[0 for _ in range(n+1)] for __ in range(n+1)] for ___ in range(n+1)]

dp[n][n][n] = 0
divT = [1/i for i in range(1,n+1)]

for x in range(n,cnt[1]+cnt[2]-1,-1):## -2だったのを-1に
    for y in range(x,cnt[2]-1,-1):##cnt[2]
        for z in range(y,-1,-1):
            delta = n*divT[n-z-1]#2枚以下を引くまで
            if x != n:
                dp[x][y][z] += (dp[x+1][y][z] + delta) * (n-x)
            if y != x:
                dp[x][y][z] += (dp[x][y+1][z] + delta) * (x-y)#x+1,y+1ではない
            if z != y:
                dp[x][y][z] += (dp[x][y][z+1] + delta)* (y-z)#x+1,y+1,z+1ではない
            dp[x][y][z] *=divT[n-z-1]

print(dp[cnt[1]+cnt[2]][cnt[2]][0])
