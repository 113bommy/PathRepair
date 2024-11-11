from sys import stdin
input = stdin.readline
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
dp1,dp2,dp3 = [0]*n,[0]*n,[0]*n
dp1[0],dp2[0],dp3[0] = a[0],b[0],0
for i in range(n):
    dp1[i]=max(dp2[i-1]+a[i],dp3[i-1],dp1[i-1])
    dp2[i]=max(dp1[i-1]+b[i],dp3[i-1],dp2[i-1])
    dp3[i]=max(dp2[i-1],dp3[i-1],dp1[i-1])
print(max(dp1[n-1],dp2[n-1],dp3[n-1]))
