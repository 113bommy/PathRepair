t = int(input())
for i in range(t):
    l = int(input())
    s = list(map(int,input().split()))
    for j in range(l):
        s[j] += j /100000.0
    sor = sorted(s)
    b = []
    for j in s:
        b.append(sor.index(j))
       
    dp = [0] * (l+1)
    
    for j in range(l):
        dp[b[j]] = 1 + dp[b[j] - 1]

    print(l-max(dp))