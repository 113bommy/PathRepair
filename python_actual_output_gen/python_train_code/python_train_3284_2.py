# arr=list(map(int,input().split()))
# arr=sorted([(n-int(x),i) for i,x in enumerate(input().split())])
# arr=[int(q)-1 for q in input().split()]
# from collections import Counter
# n=int(input())
# n,k=map(int,input().split())
# arr=list(map(int,input().split()))
# for i in range(m):
#for _ in range(int(input())):
#n=int(input())
c,d=map(int,input().split())
n,m=map(int,input().split())
k=int(input())
var=n*m-k
dp=[0]*(n*m+1)
for i in range(1,n*m+1):
    if i<n:
        dp[i]=dp[i-1]+d
    else:
        dp[i]=min(dp[i-n]+c,dp[i-1]+d)
print(min(dp[n*m-k:n*m+1]))

