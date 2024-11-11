t = int(input())

for _ in range(t):
    n,k = map(int,input().split())
    s = input()
    c = list(map(int,input().split()))
    cnt = [0 for i in range(n)]
    ans = [0 for i in range(26)]
    dp = [0 for i in range(n)]
    for i in c:
        cnt[i-1]+=1
#    print("cnt",cnt)
    dp[-1] = cnt[-1] + 1
#    print(len(dp),len(cnt))
    for i in range(n-2,-1,-1):
        dp[i] = dp[i+1]+cnt[i]
    for i in range(0,n):
        ans[ord(s[i])-97] += dp[i]
 #   print(dp)
  #  print(ord("a"))
    print(ans,sep=" ")
