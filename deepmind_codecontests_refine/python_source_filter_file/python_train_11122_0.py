def main():
    import sys
    input=sys.stdin.readline
    n=int(input())
    hp=sorted([list(map(int,input().split())) for _ in [0]*n],key=lambda x:sum(x))
    dp=[10**10]*(n+1)
    dp[0]=0
    for c,[h,p] in enumerate(hp):
        for k in range(c,-1,-1):
            if dp[k]<=h:
                dp[k+1]=min(dp[k+1],dp[k]+p)
    for i in range(n,-1,-1):
        if dp[i]!=10**10:
            print(i)
            break
if __name__=='__main__':
    main()
