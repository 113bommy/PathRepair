#from sys import stdin,stdout
#input = stdin.readline
def main():
    #t = int(input())
    t=1
    for z in range(t):
        n = int(input())
        #n, k  = map(int,input().split())
        s = input()
        ai = list(map(int,input().split()))
        dp = [0]*4
        for i in range(n):
            for j in range(1,4):
                dp[j] = min(dp[:j+1])
            if s[i] == "h":
                dp[1] = min(dp[1],dp[0])
                dp[0] += ai[i]
            elif s[i] == "a":
                dp[2] = min(dp[2],dp[1])
                dp[1] += min(dp[0],dp[1]+ai[i])
            elif s[i] == "r":
                dp[3] = min(dp[2],dp[3])
                dp[2] += min([dp[0],dp[1],dp[2]+ai[i]])
            elif s[i] == "d":
                dp[3] += min([dp[0],dp[1],dp[2],dp[3]+ai[i]])
        print(min(dp))
main()

## ""
## "h"
## "ha"
## "har"
