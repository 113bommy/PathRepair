n = int(input())
a =list(map(int,input().split()))
massiv = [0]*10**5
for i in range(n):
    massiv[a[i]-1] += 1
print(massiv)
dp = [0]*10**5
dp[0] = massiv[0]
dp[1] = massiv[1]*2
maxx = dp[0]
for i in range(2,len(dp)):
    dp[i] = massiv[i]*(i+1)+maxx
    if dp[i-1] > maxx:
        maxx = dp[i-1]
print(dp)
print(max(dp))