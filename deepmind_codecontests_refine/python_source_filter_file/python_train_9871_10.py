def main():
    import sys
    input=sys.stdin.buffer.readline
    n=int(input())
    dp=[0]*-~n
    for h,a in zip(map(int,input().split()),map(int,input().split())):
        i,s=h,0
        while i:
            t=dp[i]
            if t>s:s=t
            i-=i&-i
        s+=a
        i=h
        while i<=n:
            if s>dp[i]:dp[i]=s
            i+=i&-i
    print(dp[n])
main()