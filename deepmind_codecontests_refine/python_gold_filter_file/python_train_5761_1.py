from sys import stdin
from sys import stdout
a=input()
n=len(a)
a=list(a)[:n]
dp=[[0 for j in range(n)] for i in range(n)]
for i in range(n):
    dp[i][i]=1
for l in range(2,n+1):
    for i in range(n-l+1):
        j=i+l-1
            # print(i,j)
        if(j-i==1 and a[i]==a[j]):
            dp[i][j]=1
        else:
            temp=dp[i+1][j-1]*(a[i]==a[j])
            dp[i][j]=temp
dpr=[[0 for j in range(n)] for i in range(n)]
for i in range(n):
    dpr[i][i]=1
s=a[::-1]
for l in range(2,n+1):
    for i in range(n-l+1):
        j=i+l-1
            # print(i,j)
        if(j-i==1 and s[i]==s[j]):
            dpr[i][j]=1
        else:
            temp=dpr[i+1][j-1]*(s[i]==s[j])
            dpr[i][j]=temp
 
s=[]
 
for i in range(n):
    tempy=0
    for j in range(i,n):
        tempy=tempy+dp[i][j]
    s.append(tempy)
r=[]
for i in range(n):
    tempy=0
    for j in range(i,n):
        tempy=tempy+dpr[i][j]
    r.append(tempy)
# print(s)
# print(r)
# s=s[::-1]
tot=sum(s)
right=[]
 
for i in range(n):
    right.append(tot)
    tot=tot-r[i]
s=s[::-1]
# print(s)
# print(right)
ans=0
for i in range(n):
    j=i+1
    if(j<n):
        ans=ans+s[i]*right[j]
stdout.write(str(ans))