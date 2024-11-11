from sys import stdin
input = stdin.readline
a = str(input())
print(a)
n = len(a)
dp = [0]*n
l = 0
for i in range(n-1):
    if a[i]==a[i+1]:
        l+=1
        dp[i]=l
    else:
        dp[i]=l
dp[n-1]=dp[n-2]
m = int(input())
for _ in range(m):
    l,r = list(map(int,input().split()))
    if l-2>=0:
        print(dp[r-2]-dp[l-2])
    else:
        print(dp[r-2])
