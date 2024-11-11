def popcount(x):
    x = x - ((x >> 1) & 0x5555555555555555)
    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f0f0f0f0f
    x = x + (x >> 8) 
    x = x + (x >> 16) 
    x = x + (x >> 32) 
    return x & 0x0000007f
f=popcount
a=[]
n=int(input())
for _ in range(n):
    a.append(tuple(map(int,input().split())))

S=1<<n
dp=[0]*(S)


dp[0]=1

for s in range(1,S):
    i=f(s)
    for j in range(n):
        if s>>j&1:
            if a[i-1][j]:
                dp[s]+=dp[s-(1<<j)]
        else:
            dp[s]%=10**9+7
            continue
# print(dp)
print(dp[S-1]%(10**9+7))