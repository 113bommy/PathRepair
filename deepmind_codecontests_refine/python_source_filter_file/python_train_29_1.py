from sys import stdin,stdout

dp=[]
M=10**9+7
for i in range(200011):
    if i<10:
        dp.append(1)
    else:
        dp.append((dp[i-9]+dp[i-10])%M)

for _ in range(int(stdin.readline())):
    n,m=stdin.readline().split()
    m=int(m)
    M=10**9+7
    ans=0
    for i in n:
        ans+=(dp[m+int(i)]%M)
    stdout.write(str(ans)+'\n')