n,k=map(int,input().split())
a=list(map(int,input().split()))
dp=[0]*(k+1+1234)

for i in range(0,k+1):
    if dp[i] == 0:
        for x in a:
            dp[min(i+x,k)] =1

print("First" if dp[k] else "Second")