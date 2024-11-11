import sys
input=sys.stdin.readline
def main():
    n=int(input())
    al=tuple(map(int,input().split()))
    arr=[0,0,0]
    for i in al:
        arr[i-1]+=1
    dp=[[[0 for k in range(n+1)] for j in range(n+1)] for i in range(n+1)]
    for c in range(n+1):
        for b in range(n+1-c):
            for a in range(n-b-c+1):
                if a==b==c==0:
                    continue
                if 0<=c-1<=n and 0<=b+1<=n:
                    dp[a][b][c]+=dp[a][b+1][c-1]*c/n
                if 0<=b-1<=n and 0<=a+1<=n:
                    dp[a][b][c]+=dp[a+1][b-1][c]*b/n
                if 0<=a-1<=n:
                    dp[a][b][c]+=dp[a-1][b][c]*a/n
                dp[a][b][c]=(dp[a][b][c]+1)*n/(a+b+c)
    print(dp[arr[0]][arr[1]][arr[2]])
if __name__=='__main__':
    main()
