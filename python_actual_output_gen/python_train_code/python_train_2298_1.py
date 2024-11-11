N = int(input())

A = list(map(int,input().split()))


b = sorted(list(A))
dp = [0]*(max(A)+4)

m_a = max(A)
for i in b:
    dp[i] += 1
    if dp[i]==1 :
        for j in range(i*2, m_a,i):
            dp[j] +=100

print(dp.count(1))