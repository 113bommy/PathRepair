from math import inf
def main():
    count=int(input())
    string=input()
    arr=input().split()
    hard="hard"
    dp=[[inf for y in range(5)] for x in range(count+1)]
    dp[0][0]=0
    for x in range(count):
        for y in range(4):
            if (string[x]==hard[y]):
                dp[x+1][y+1]=min(dp[x][y],dp[x+1][y+1])
                dp[x+1][y]=min(dp[x][y]+int(arr[x]),dp[x+1][y])
            else:
                dp[x+1][y]=min(dp[x][y],dp[x+1][y])
    mini=0
    for x in range(4):
        mini=min(mini,dp[-1][x])
    print(mini)
main()
    
